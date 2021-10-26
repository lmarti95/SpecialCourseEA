#include "EvolutionaryAlgorithms.h"

#include "CostFunctions.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

long nextPosition = -1;
std::random_device dev;
std::mt19937 rng(dev());
double l;

int* CreateRandomBitString(int N)
{
	int* bitString = new int[N];

	std::uniform_int_distribution<std::mt19937::result_type> coin(0, 1);

	for(int i = 0; i < N; ++i)
	{
		bitString[i] = coin(rng);
	}

	return bitString;
}

int* CreateRandomBitStringFromParents(int N, std::vector<std::pair<int*, int>> aParents, int* aFitnessValue)
{
	int* bitString = new int[N];

	std::uniform_int_distribution<std::mt19937::result_type> selectParent(0, aParents.size()-1);

	auto selection = selectParent(rng);

	std::copy(aParents.at(selection).first, aParents.at(selection).first + N, bitString);

	*aFitnessValue = aParents.at(selection).second;

	return bitString;
}

int FlipBits(const int N, int* aBitString, int aNext)
{
	int fitnessValueChange = 0;
	long start = 0;

	while(aNext != -1)
	{
		auto temp = start + aNext;
		if(aBitString[start + aNext] == 0)
		{
			aBitString[start + aNext] = 1;
			fitnessValueChange++;
		}
		else
		{
			aBitString[start + aNext] = 0;
			fitnessValueChange--;
		}
		start = start + aNext + 1;
		aNext = GetNextPosition(N - start - 1);
	}

	return fitnessValueChange;
}

std::pair<long, double> OnePlusOneEA(int N, CostFunction aCostFunction)
{
	int* bitString = CreateRandomBitString(N);

	int* bitStringPrime = new int[N];

	std::uniform_int_distribution<std::mt19937::result_type> p(1, N);

	int fitnessValue = aCostFunction(bitString, N);
	int newFitnessValue;

	long iterations = 0;
	bool justUpdated = false;

	auto start = std::chrono::steady_clock::now();

	l = log(1.0 - 1.0 / N);

	while(fitnessValue != N)
	{
		iterations++;

		if(!justUpdated)
		{
			std::copy(bitString, bitString + N, bitStringPrime);
			newFitnessValue = fitnessValue;
		}
		else
		{
			justUpdated = false;
		}

		long next = GetNextPosition(N - 1);
		if(next != -1)
		{
			newFitnessValue += FlipBits(N, bitStringPrime, next);
		}
		else
		{
			continue;
		}

		if(aCostFunction != OneMax)
		{
			newFitnessValue = aCostFunction(bitStringPrime, N);
		}
		
		if(newFitnessValue > fitnessValue)
		{
			fitnessValue = newFitnessValue;
			std::copy(bitStringPrime, bitStringPrime + N, bitString);
			justUpdated = true;
		}

	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsedSeconds = end - start;

	//std::cout << "It took " << iterations << " iterations to run the 1+1 EA on population size " << N << " and " << elapsedSeconds.count() << " seconds." << std::endl;

	delete[] bitString;
	delete[] bitStringPrime;

	return std::make_pair(iterations, elapsedSeconds.count());
}

std::pair<long, double> MuPlusOneEA(const int N, CostFunction aCostFunction, int aMuSize)
{
	std::vector<std::pair<int*, int>> population;

	for(int i = 0; i < aMuSize; ++i)
	{
		int* bitString = CreateRandomBitString(N);
		int fitnessValue = aCostFunction(bitString, N);
		population.push_back(std::make_pair(bitString, fitnessValue));
	}

	std::uniform_int_distribution<std::mt19937::result_type> p(1, N);

	int* bitStringPrime;

	int newFitnessValue = 0;
	long iterations = 0;
	bool justUpdated = false;

	auto start = std::chrono::steady_clock::now();

	while(!justUpdated || N != std::max_element(population.begin(), population.end(), [](auto a, auto b)
		{
		return a.second < b.second;
		})->second)
	{
		iterations++;

		if(justUpdated)
		{
			justUpdated = false;
		}

		long next = GetNextPosition(N-1);
		if(next != -1)
		{
			bitStringPrime = CreateRandomBitStringFromParents(N, population, &newFitnessValue);
			newFitnessValue += FlipBits(N, bitStringPrime, next);
		}
		else
		{
			continue;
		}

		if(aCostFunction != OneMax)
		{
			newFitnessValue = aCostFunction(bitStringPrime, N);
		}

		auto min = std::min_element(population.begin(), population.end(), [](auto a, auto b)
			{
				return a.second < b.second;
			});

		if(newFitnessValue > min->second)
		{
			int* bitString = new int[N];
			std::copy(bitStringPrime, bitStringPrime + N, bitString);

			delete[] min->first;
			population.erase(min);
			population.push_back(std::make_pair(bitString, newFitnessValue));

			justUpdated = true;
		}

		delete[] bitStringPrime;
	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsedSeconds = end - start;

	//std::cout << "It took " << iterations << " iterations to run the Mu+1 EA on population size " << N << " and " << elapsedSeconds.count() << " seconds with parent size  " << aMuSize  << ". "<< std::endl;

	for(int i = 0; i < aMuSize; ++i)
	{
		delete[] population.at(i).first;
	}

	return std::make_pair(iterations, elapsedSeconds.count());
}

std::pair<long, double> OnePlusOneEAWrapper(int N, CostFunction aCostFunction, int temp)
{
	return OnePlusOneEA(N, aCostFunction);
}

long SavePosition(long N)
{
	if(nextPosition > N)
	{
		nextPosition = nextPosition - N-1;
		return -1;
	}
	else
	{
		long next = nextPosition;
		nextPosition = -1;
		return next;
	}
}

long GetNextPosition(long N)
{
	std::uniform_real_distribution<> p(0.0, 1.0);
	if(nextPosition == -1)
	{
		auto x = p(rng);
		nextPosition = (long)floor(log(x) / l);
	}

	return SavePosition(N);
}