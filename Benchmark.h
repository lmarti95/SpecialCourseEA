#pragma once

#include "EvolutionaryAlgorithms.h"

const int repeat = 30;

typedef std::pair<long, double>(*EAFunction)(int, CostFunction, int);

std::string EAFunctionNameLookUp(EAFunction aEAFunction);

std::vector<double> RunEA(CostFunction aCostFunction, EAFunction aEAFunction, std::vector<int> aLengths, std::vector<int> aMus);

void savePlot(std::vector<int> aX, std::vector<double> aY, std::string aXLabel, std::string aYLabel, std::string aTitle);

void savePlotMu(std::vector<int> aX, std::vector<double> aY, std::string aTitle, std::vector<int> aMus);