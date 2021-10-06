#include "Benchmark.h"

#include <iostream>

void RunEA(CostFunction aCostFunction, EAFunction aEAFunction, std::vector<int> aLengths, std::vector<int> aMus)
{
	for(auto& length : aLengths)
	{		
		for(auto& Mu : aMus)
		{
			long long iterations = 0;
			double  time = 0;
			for(int i = 0; i < repeat; ++i)
			{
				auto result = aEAFunction(length, aCostFunction, Mu);
				iterations += result.first;
				time += result.second;
			}

			double averageRepeat = iterations / repeat;
			double averageTime = time / repeat;

			std::cout << "Average iterations for EA with Mu size "<< Mu <<" is " << averageRepeat <<
				" average time is " << averageTime << " seconds and N is " << length << "." << std::endl;
		}
	}	
}