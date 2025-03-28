#include "PascalTriangleCalculator.h"
#include <vector>
#include <cassert>
#include <ranges>
#include <algorithm>

std::vector<std::vector<int>> PascalTriangleCalculator::CalculateTriangle(int rows)
{
	std::vector<std::vector<int>> triangle{ {1} };
	triangle.reserve(rows);

	for (int i = 1; i < rows; i++) {
		triangle.emplace_back(CalculateNextRow(triangle.back()));
	}

	assert(triangle.size() == rows);

	return triangle;
}

std::vector<int> PascalTriangleCalculator::CalculateNextRow(const std::vector<int>& previousRow)
{
	auto newRow = std::vector<int>{ 1 };

	if (previousRow.empty()) {
		return newRow;
	}

	for (size_t i = 0; i + 1 < previousRow.size(); ++i) {
		newRow.emplace_back(previousRow[i] + previousRow[i + 1]);
	}

	newRow.emplace_back(1);

	auto front = newRow | std::views::take(newRow.size() / 2);
	auto back = newRow | std::views::reverse | std::views::take(newRow.size() / 2);

	assert(std::ranges::equal(front, back));

	return newRow;
}
