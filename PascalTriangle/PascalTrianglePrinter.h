#pragma once
#include <vector>

class PascalTrianglePrinter
{
public:
	void Print(const std::vector<std::vector<int>>& pascalTriangle);
	void PrintOddOne(const std::vector<std::vector<int>>& pascalTriangle);

private:
	int BiggestNumberSize(const std::vector<int>& row);

};

