#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include <string>

using namespace std;

void VectorPrinter(std::ranges::input_range auto&& range) {
	std::ranges::for_each(range, [](const auto& e) { std::cout << e << "; "; });
	std::cout << '\n';
}

int main() {
	std::vector<int> _numbers{ 1, 2, 3, 4, 5 };
	auto _view = _numbers | std::views::take(2);

	VectorPrinter(_numbers);
	VectorPrinter(_view);

	_numbers[0] = 122;
	VectorPrinter(_view);

	return 0;
}