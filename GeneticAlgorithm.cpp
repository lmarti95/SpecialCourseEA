#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int N, CostFunction* aCostFunction) : EvolutionaryAlgorithm(N, aCostFunction)
{
}

int* GeneticAlgorithm::CreateMutatedOffSpring(std::vector<std::pair<int*, double>> aParents)
{
	int* bitString = new int[mN];

	for(unsigned int i = 0; i < aParents.size(); ++i)
	{
		for(size_t j = i / aParents.size() * mN; j < (static_cast<unsigned long long>(i) + 1) / aParents.size() * mN; ++j)
		{
			bitString[j] = aParents.at(i).first[j];
		}
	}

	return bitString;
}
