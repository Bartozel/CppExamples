#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include <string>

void ReferenceChanges(std::string& reference) {
	reference = "Hey How";
}

int main() {
	std::string str = "Ahoj";
	std::string& strRef = str;

	std::cout << str + "\n";
	std::cout << "Reference: " + strRef + "\n";

	ReferenceChanges(strRef);
	std::cout << "Reference 2: " + strRef + "\n";

	return 0;
}

