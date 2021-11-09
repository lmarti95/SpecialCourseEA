#include "Benchmark.h"
#include "Cliff.h"
#include "CostFunction.h"
#include "Jump.h"
#include "LeadingOnes.h"
#include "OneCommaLambdaEA.h"
#include "OneMax.h"
#include "OnePlusLambdaCommaLambdaGA.h"
#include "OnePlusOneEA.h"
#include "MuPlusOneEA.h"
#include "TwoPlusOneGA.h"

#include <iostream>

int main()
{
	int N = 250;

	OneMax om = OneMax(N);
	LeadingOnes lo = LeadingOnes(N);
	Cliff cl = Cliff(N);
	Jump ju = Jump(N, 2);

	CostFunction* co = &lo;

	Benchmark b = Benchmark();

	OnePlusOneEA ea = OnePlusOneEA(N, co);
	ea.SetOptimizationLevel(OnePlusOneEAOptimization::All);
	b.RunEA(&ea);

	MuPlusOneEA mu = MuPlusOneEA(N, co, 16);
	b.RunEA(&mu);

	TwoPlusOneGA ga = TwoPlusOneGA(N, co);
	b.RunEA(&ga);

	OnePlusLambdaCommaLambdaGA oneLLGA = OnePlusLambdaCommaLambdaGA(N, co, 16);
	b.RunEA(&oneLLGA);

	OneCommaLambdaEA oneclea= OneCommaLambdaEA(N, co, 16);
	b.RunEA(&oneclea);
}