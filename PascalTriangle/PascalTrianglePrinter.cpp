#include "PascalTrianglePrinter.h"

#include <iterator>
#include <algorithm>
#include <iostream>
#include <fmt/core.h>

void PascalTrianglePrinter::Print(const std::vector<std::vector<int>>& pascalTriangle)
{
	int spaceForNumber = BiggestNumberSize(pascalTriangle.back());
	std::string spacesStr((spaceForNumber * pascalTriangle.size()) / 2, ' ');
	for (const auto& row : pascalTriangle) {

		spacesStr.resize(spacesStr.size() - (spaceForNumber / 2));

		std::cout << spacesStr;
		for (auto val : row) {
			std::cout << fmt::format("{:^{}}", val, spaceForNumber);
		}
		std::cout << "\n";
	}
}

void PascalTrianglePrinter::PrintOddOne(const std::vector<std::vector<int>>& pascalTriangle)
{
	int size = 2;
	std::string spacesStr((size * pascalTriangle.size())/2, ' ');
	for (const auto& row : pascalTriangle) {

		spacesStr.resize(spacesStr.size() - (size/2));

		std::cout << spacesStr;
		for (auto val : row) {

			if (val % 2 != 0) {
				std::cout << fmt::format("{:^{}}", '*', size);
			}
			else {
				std::cout << fmt::format("{:^{}}", ' ', size);
			}
		}
		std::cout << "\n";
	}
}

int PascalTrianglePrinter::BiggestNumberSize(const std::vector<int>& row)
{
	std::vector<int>::const_iterator it = row.begin();
	auto centerValue = *(row.begin() + row.size() / 2);
	int size = 100;
	int i = 1;

	while (centerValue > size) {
		size *= 100;
		i++;
	}

	return (i * 2) + 2;
}

