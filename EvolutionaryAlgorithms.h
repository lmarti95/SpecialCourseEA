#pragma once

#include <random>

typedef int (*CostFunction)(int*, int);

int* CreateRandomBitString(int N);
int* CreateRandomBitStringFromParents(int N, std::vector<std::pair<int*, int>> aParents);

int FlipBits(const int N, int* aBitString, int next);

std::pair<long, double> OnePlusOneEA(int N, CostFunction aCostFunction);
std::pair<long, double> MuPlusOneEA(const int N, CostFunction aCostFunction, int aMuSize);

std::pair<long, double> OnePlusOneEAWrapper(int N, CostFunction aCostFunction, int temp = 0);

long SavePosition(long* aPosition, long N);
long GetNextPosition(long N);