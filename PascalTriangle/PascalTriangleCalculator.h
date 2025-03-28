#pragma once
#include <vector>

class PascalTriangleCalculator
{
public:
	std::vector<std::vector<int>> CalculateTriangle(int rows);

private:
	std::vector<int> CalculateNextRow(const std::vector<int>& previousRow);
};

