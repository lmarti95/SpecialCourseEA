#include "CostFunctions.h"

int OneMax(int* aBitString, int N)
{
	int sum = 0;

	for(int i = 0; i < N; ++i)
	{
		sum += aBitString[i];
	}

	return sum;
}

int LeadingOnes(int* aBitString, int N)
{
	int max1s = 0;
	int temp = 0;

	for(int i = 0; i < N; ++i)
	{
		if(aBitString[i] == 1)
		{
			temp++;
		}
		else
		{
			if(temp > max1s)
			{
				max1s = temp;
			}
			temp = 0;
		}
	}

	if(temp > max1s)
	{
		max1s = temp;
	}

	return max1s;
}