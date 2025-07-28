#pragma once
#include <vector>

class IPrimeNumberGenerator
{
public:
	virtual std::vector<unsigned> GetPrimeNumbers(int highBound) const = 0;
	virtual std::vector<unsigned> GetPrimeNumbers(int lowBound, int highBound) const = 0;
};

