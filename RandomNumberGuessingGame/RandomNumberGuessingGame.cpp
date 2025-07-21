#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include <format>

#include "NumberGenerator.h"

std::optional<int> read_number(std::istream& in)
{
	int result{};

	if (in >> result) {
		return result;
	}

	in.clear();
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return {};
}

unsigned Input() {
	std::cout << "Guess the number.\n";

	unsigned number;
	while (!(std::cin >> number)) {
		std::cin.clear();
		std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(), '\n'
		);
		std::cout << "Hey man, put some meaningful input.\n";
	}

	return number;
}

void GuessNumber(unsigned number,  std::function<std::string(int number, int guess)> callable) {

	std::cout << "Guess a number.\n";

	std::optional<int> guess;

	while ((guess = read_number(std::cin))) {

		if (guess.value() == number) {
			std::cout << "Well done. \n";
			return; 
		}
		else {
			std::cout << callable(number, guess.value());
		}
	}
}

int main()
{
	NumberGenerator ng(0, 10000);
	GuessNumber(ng.GetRandomNumber(), [](int number, int guess) {return std::string(std::format("Your guess was too {}.\n", number > guess ? "high" : "low")); });
}