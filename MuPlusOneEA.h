#pragma once

#include "EvolutionaryAlgorithm.h"

class MuPlusOneEA : public EvolutionaryAlgorithm
{
public:
	MuPlusOneEA(int aN, CostFunction* aCostFunction, int aPopulation);
	~MuPlusOneEA();

	MuPlusOneEA(const MuPlusOneEA&) = delete;
	MuPlusOneEA& operator= (const MuPlusOneEA&) = delete;

	void CreateInitialPopulation();
	void DeletePopulation();

	std::pair<int*, double> CreateRandomBitStringFromParents();

	std::pair<long long, double> RunEA() override;
private:
	int mPopulationSize;
	std::vector<std::pair<int*, double>> mPopulation;
	
};

