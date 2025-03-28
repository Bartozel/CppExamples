#include <iostream>
#include <string>
#include <optional>


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

    std::string in;
    std::getline(std::cin, in);

    while (!()) {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
        std::cout << "Hey man, put some meaningful input.\n";
    }


    return ;
}

void GuessNumber(unsigned guesingNumber) {

    std::cout << "Guess a number.\n";

    while (guesingNumber != Input()) {
        std::cout << "Guess again.\n";
    }

    std::cout << "Well done. \n";
}

int main()
{
    GuessNumber(42);
}