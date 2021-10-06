#include "Benchmark.h"
#include "CostFunctions.h"
#include "EvolutionaryAlgorithms.h"

#include <iostream>

int main()
{
	std::vector<int> lengths;
	lengths.push_back(100);
	/*lengths.push_back(200);
	lengths.push_back(500);
	lengths.push_back(1000);
	lengths.push_back(2500);
	lengths.push_back(5000);
	lengths.push_back(10000);*/

	std::vector<int> Mus;
	Mus.push_back(2);
	Mus.push_back(4);
	Mus.push_back(8);
	Mus.push_back(16);
	Mus.push_back(32);
	Mus.push_back(64);
	Mus.push_back(128);

	std::vector<int> OneMu;
	OneMu.push_back(1);

	//RunEA(OneMax, OnePlusOneEAWrapper, lengths, OneMu);
	//RunEA(LeadingOnes, OnePlusOneEAWrapper, lengths, OneMu);

	RunEA(OneMax, MuPlusOneEA, lengths, Mus);
	//RunEA(LeadingOnes, MuPlusOneEA, lengths, Mus);
}