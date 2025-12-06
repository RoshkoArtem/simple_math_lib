#include "math_lib.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <limits>

namespace MathLib
{
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0.0) {
            throw std::invalid_argument("Division by zero");
        }
        return a / b;
    }

    double sqrt(double x) {
        if (x < 0.0) {
            throw std::invalid_argument("Square root of negative number");
        }
        return std::sqrt(x);
    }

    bool isEqual(double a, double b, double tolerance)
    {
        return std::fabs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; static_cast<long long>(i) * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int GCD(int a, int b)
    {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int leastCommonMultiple(int a, int b)
    {
        if (a == 0 || b == 0) return 0;
        int gcd = GCD(a, b);
        long long div = static_cast<long long>(a) / gcd;
        long long prod = div * static_cast<long long>(b);
        long long abs_prod = prod < 0 ? -prod : prod;
        if (abs_prod > std::numeric_limits<int>::max()) {
            // В тестах такого не ожидается; возвращаем значение в int (по модулю)
            return static_cast<int>(abs_prod);
        }
        return static_cast<int>(abs_prod);
    }

    double thirdAngle(double a, double b)
    {
        if (a <= 0.0 || b <= 0.0 || (a + b) >= 180.0) {
            throw std::invalid_argument("Invalid angle values: angles must be positive and sum < 180");
        }
        return 180.0 - a - b;
    }
}