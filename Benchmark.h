#pragma once

#include "EvolutionaryAlgorithms.h"

const int repeat = 30;

typedef std::pair<long, double>(*EAFunction)(int, CostFunction, int);

std::string EAFunctionNameLookUp(EAFunction aEAFunction);

void RunEA(CostFunction aCostFunction, EAFunction aEAFunction, std::vector<int> aLengths, std::vector<int> aMus);