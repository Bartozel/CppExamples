#include <random>
#include <vector>

#pragma once
class NumberGenerator
{
public:
	NumberGenerator(int lowBound, int highBound);
	int GetRandomNumber();
	bool IsPrime(int number);
	int GetRandomPrime();

private:
	std::vector<unsigned> GeneratePrimeNumberCollection(int highBound);

private:
	std::random_device m_rd;
	std::mt19937 m_engine;
	std::uniform_int_distribution<int> m_dist;
	std::vector<unsigned> m_primeNumbers; // should be in different class
};