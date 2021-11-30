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
	/*int N = 250;

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
	b.RunEA(&oneclea);*/

	
	/*std::vector<double> iterations1;
	std::vector<double> iterations2;
	std::vector<double> time1;
	std::vector<double> time2;
	std::vector<int> Ns;

	for(int i = 100; i < 2501; i+=100)
	{
		if(i > 1000)
		{
			i += 100;
		}

		int N = i;
		Ns.push_back(N);

		Benchmark b = Benchmark();
		OneMax om = OneMax(N);

		OnePlusOneEA ea = OnePlusOneEA(N, &om);
		auto pair = b.RunEA(&ea);
		iterations1.push_back(pair.first);
		time1.push_back(pair.second);

		TwoPlusOneGA ga = TwoPlusOneGA(N, &om);
		pair = b.RunEA(&ga);
		iterations2.push_back(pair.first);
		time2.push_back(pair.second);
	}

	Benchmark b = Benchmark();

	b.SavePlot(Ns, iterations1, "N", "iterations", "iterations1");
	b.SavePlot(Ns, iterations2, "N", "iterations", "iterations2");

	b.SavePlot(Ns, time1, "N", "time", "time1");
	b.SavePlot(Ns, time2, "N", "time", "time2");*/

	/*std::vector<double> iterations;
	std::vector<int> Is;

	for(int i = 13; i < 19; ++i)
	{
		int N = i;

		for(int j = 2; j < 6; ++j)
		{
			Is.push_back(j);
			Benchmark b = Benchmark();
			Jump ju = Jump(N, j);

			OnePlusLambdaCommaLambdaGA ea = OnePlusLambdaCommaLambdaGA(N, &ju, 4);
			auto pair = b.RunEA(&ea);
			iterations.push_back(pair.first);
		}

		Benchmark b = Benchmark();
		b.SavePlot(Is, iterations, "Is", "iterations", "Jump on (1+(lambda,lambda)) EA N = " + std::to_string(i));

		iterations.clear();
		Is.clear();
	}
	*/

	std::vector<double> iterations;
	std::vector<int> Is;

	for(int i = 13; i < 19; ++i)
	{

		int N = i;

		for(int j = 2; j < 9; ++j)
		{
			Is.push_back(j);
			Benchmark b = Benchmark();
			Cliff ci = Cliff(N);

			OneCommaLambdaEA ea = OneCommaLambdaEA(N, &ci, j);

			auto pair = b.RunEA(&ea);
			iterations.push_back(pair.first);
		}

		Benchmark b = Benchmark();
		b.SavePlot(Is, iterations, "Lambda", "Number of iterations", "Cliff on (1+lambda) EA N = " + std::to_string(i));

		iterations.clear();
		Is.clear();
	}

	/*std::vector<double> iterations;
	std::vector<int> Is;

	int N = 16;

	for(int i = 2; i < 9; ++i)
	{
		Is.push_back(i);
		Benchmark b = Benchmark();
		Cliff ci = Cliff(N);

		OnePlusLambdaCommaLambdaGA ea = OnePlusLambdaCommaLambdaGA(N, &ci, i);

		auto pair = b.RunEA(&ea);
		iterations.push_back(pair.first);
	}

	Benchmark b = Benchmark();
	b.SavePlot(Is, iterations, "Lambda", "Number of iterations", "Cliff on (1+(lambda,lambda)) GA N = 16");*/

	/*int N = 1000;
	std::vector<double> iterations;
	std::vector<int> Is;

for(int i = 2; i < 129; i=i*2)
{
	Is.push_back(i);
	Benchmark b = Benchmark();
	OneMax ci = OneMax(N);

	MuPlusOneEA ea = MuPlusOneEA(N, &ci, i);

	auto pair = b.RunEA(&ea);
	iterations.push_back(pair.first);
}

Benchmark b = Benchmark();
b.SavePlot(Is, iterations, "Population Size", "Number of iterations", "Mu + 1EA on OneMax N = 1000");*/

}