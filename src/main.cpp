#include <iostream>
#include "math_lib.h"

int main(int argc, char* argv[])
{
    double num1 = 10.5, num2 = 2.5;

    std::cout << "Addition: " << MathLib::add(num1, num2) << std::endl;
    std::cout << "Subtraction: " << MathLib::subtract(num1, num2) << std::endl;
    std::cout << "Multiplication: " << MathLib::multiply(num1, num2) << std::endl;
    std::cout << "Division: " << MathLib::divide(num1, num2) << std::endl;
    std::cout << "Square root: " << MathLib::sqrt(num1) << std::endl;

    // GCD/LCM працюють з int, тому явно перетворимо
    int a = 10, b = 6;
    std::cout << "GCD(" << a << ", " << b << ") = " << MathLib::GCD(a, b) << std::endl;
    std::cout << "LCM(" << a << ", " << b << ") = " << MathLib::leastCommonMultiple(a, b) << std::endl;

    return 0;
}