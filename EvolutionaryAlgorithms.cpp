#include "EvolutionaryAlgorithms.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

int* CreateRandomBitString(int N)
{
	int* bitString = new int[N];

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> coin(0, 1);

	for(int i = 0; i < N; ++i)
	{
		bitString[i] = coin(rng);
	}

	return bitString;
}

int* CreateRandomBitStringFromParents(int N, std::vector<std::pair<int*, int>> aParents)
{
	int* bitString = new int[N];

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> selectParent(0, aParents.size()-1);

	auto selection = selectParent(rng);

	std::copy(aParents.at(selection).first, aParents.at(selection).first + N, bitString);

	return bitString;
}

std::pair<long, double> OnePlusOneEA(int N, CostFunction aCostFunction)
{
	int* bitString = CreateRandomBitString(N);

	int* bitStringPrime = new int[N];

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> p(1, N);

	int fitnessValue = aCostFunction(bitString, N);
	int newFitnessValue = 0;

	long iterations = 0;
	bool justUpdated = false;

	auto start = std::chrono::steady_clock::now();

	while(fitnessValue != N)
	{
		iterations++;

		if(!justUpdated)
		{
			std::copy(bitString, bitString + N, bitStringPrime);
		}
		else
		{
			justUpdated = false;
		}
		

		for(int i = 0; i < N; ++i)
		{
			if(p(rng) == N)
			{
				if(bitStringPrime[i] == 0)
				{
					bitStringPrime[i] = 1;
				}
				else
				{
					bitStringPrime[i] = 0;
				}
			}
		}

		newFitnessValue = aCostFunction(bitStringPrime, N);
		
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

std::pair<long, double> MuPlusOneEA(int N, CostFunction aCostFunction, int aMuSize)
{
	std::vector<std::pair<int*, int>> population;

	for(int i = 0; i < aMuSize; ++i)
	{
		int* bitString = CreateRandomBitString(N);
		int fitnessValue = aCostFunction(bitString, N);
		population.push_back(std::make_pair(bitString, fitnessValue));
	}

	std::random_device dev;
	std::mt19937 rng(dev());
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

		bitStringPrime = CreateRandomBitStringFromParents(N, population);

		for(int i = 0; i < N; ++i)
		{
			if(p(rng) == N)
			{
				if(bitStringPrime[i] == 0)
				{
					bitStringPrime[i] = 1;
				}
				else
				{
					bitStringPrime[i] = 0;
				}
			}
		}

		newFitnessValue = aCostFunction(bitStringPrime, N);

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