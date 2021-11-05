#pragma once
class CostFunction
{
public:
	CostFunction(int aN) { mN = aN; }

	virtual double GetMaximumFitnessValue() = 0;
	virtual double GetFitnessValue(int* aBitString) = 0;

	void SetN(int aN) { mN = aN; }
	int GetN() { return mN; }
protected:
	int mN;
};

