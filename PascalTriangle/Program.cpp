#include <iostream>
#include <ranges>
#include "PascalTriangleCalculator.h"
#include "PascalTrianglePrinter.h"

int main()
{
	PascalTriangleCalculator calculator;
	PascalTrianglePrinter printer;

	auto triangle = calculator.CalculateTriangle(15);
	printer.Print(triangle);
	printer.PrintOddOne(triangle);

	auto v = std::vector<int>{ 0,1,2,3,4,5,6 };
	auto view = std::views::filter(v, [](int i) { return i < 3; });

	return 0;
}