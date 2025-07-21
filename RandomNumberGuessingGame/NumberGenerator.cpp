#include "NumberGenerator.h"

NumberGenerator::NumberGenerator(int lowBound, int highBound) :
	m_rd(),
	m_engine(m_rd()),
	m_dist(lowBound, highBound),
	m_primeNumbers(GeneratePrimeNumberCollection(highBound))
{

}

int NumberGenerator::GetRandomNumber() {
	return m_dist(m_engine);
}

int NumberGenerator::GetRandomPrime() {
	size_t numberOfPrimes = m_primeNumbers.size();
	std::uniform_int_distribution<int> dist(0, numberOfPrimes - 1);

	int randomIndex = dist(m_engine);
	return m_primeNumbers[randomIndex];
}

bool NumberGenerator::IsPrime(int n) {
	if (n <= 1) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	// Check for divisors from 5 to sqrt(n)
	// Skip even numbers and multiples of 3
	int limit = static_cast<int>(std::sqrt(n));
	for (int i = 5; i <= limit; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}

std::vector<unsigned> NumberGenerator::GeneratePrimeNumberCollection(int highBound) {

	std::vector<unsigned> primeNumbers;
	primeNumbers.reserve(100);
	int numberOfImputs = 0;

	for (size_t i = 0; i <= highBound; i++) {
		if (IsPrime(i)) {
			primeNumbers.emplace_back(i);
			numberOfImputs++;
		}
	}

	return std::vector<unsigned> (primeNumbers.begin(), primeNumbers.begin() + numberOfImputs);
}