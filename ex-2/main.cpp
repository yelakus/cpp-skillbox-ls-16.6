#include <iostream>

int main() {
    std::string firstNumber, secondNumber;
    std::cout << "First number and second number:";
    std::cin >> firstNumber >> secondNumber;

    double res = std::stod(firstNumber + "." + secondNumber);

    std::cout << "Double num + 1 = " << res + 1.0;
}
