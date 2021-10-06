#pragma once

#include <random>

typedef int (*CostFunction)(int*, int);

int* CreateRandomBitString(int N);
int* CreateRandomBitStringFromParents(int N, std::vector<std::pair<int*, int>> aParents);

std::pair<long, double> OnePlusOneEA(int N, CostFunction aCostFunction);
std::pair<long, double> MuPlusOneEA(int N, CostFunction aCostFunction, int aMuSize);

std::pair<long, double> OnePlusOneEAWrapper(int N, CostFunction aCostFunction, int temp = 0);