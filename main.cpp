#include "Benchmark.h"
#include "CostFunctions.h"
#include "EvolutionaryAlgorithms.h"

#include <iostream>

int main()
{
	std::vector<int> lengths;
	lengths.push_back(20);
	/*lengths.push_back(50);
	lengths.push_back(100);
	lengths.push_back(200);
	lengths.push_back(300);
	lengths.push_back(400);
	lengths.push_back(500);
	lengths.push_back(600);
	lengths.push_back(700);
	lengths.push_back(800);
	lengths.push_back(900);
	lengths.push_back(1000);
	lengths.push_back(1100);
	lengths.push_back(1200);
	lengths.push_back(1300);
	lengths.push_back(1400);
	lengths.push_back(1500);
	lengths.push_back(1600);
	lengths.push_back(1700);
	lengths.push_back(1800);
	lengths.push_back(1900);
	lengths.push_back(2000);
	lengths.push_back(2100);
	lengths.push_back(2200);
	lengths.push_back(2300);
	lengths.push_back(2400);
	lengths.push_back(2500);*/

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

	auto iterations = RunEA(OneMax, OnePlusOneEAWrapper, lengths, OneMu);
	//savePlot(lengths, iterations, "N", "Iterations", "(1+1)EA on OneMax");

	//iterations = RunEA(LeadingOnes, OnePlusOneEAWrapper, lengths, OneMu);
	//savePlot(lengths, iterations, "N", "Iterations", "(1+1)EA on LeadingOnes");

	//iterations = RunEA(OneMax, MuPlusOneEA, lengths, Mus);
	//savePlotMu(lengths, iterations, "Mu+1EA on OneMax on different N size", Mus);
	//iterations = RunEA(LeadingOnes, MuPlusOneEA, lengths, Mus);
	//savePlotMu(lengths, iterations, "Mu+1EA on LeadingOnes on different N size", Mus);
	//savePlot(lengths, iterations, "N", "Iterations", "(2+1)EA on LeadingOnes");
}