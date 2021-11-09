#pragma once

#include "EvolutionaryAlgorithm.h"

class Benchmark {
public:
	int GetRepeat() { return mRepeat; }
	void SetRepeat(int aRepeat) { mRepeat = aRepeat; }

	double RunEA( EvolutionaryAlgorithm* aEA);

	void SavePlot(std::vector<int> aX, std::vector<double> aY, std::string aXLabel, std::string aYLabel, std::string aTitle);

	void SavePlotMu(std::vector<int> aX, std::vector<double> aY, std::string aTitle, std::vector<int> aMus);
private:
	int mRepeat = 30;
};