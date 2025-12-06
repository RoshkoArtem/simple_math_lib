#pragma once

#include <stdexcept>

namespace MathLib
{
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    double sqrt(double x);

    bool isEqual(double a, double b, double tolerance = 1e-9);

    bool isPrime(int n);

    int GCD(int a, int b);
    int leastCommonMultiple(int a, int b);

    double thirdAngle(double a, double b);
}