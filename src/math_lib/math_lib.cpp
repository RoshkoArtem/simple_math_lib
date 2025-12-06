#include "math_lib.h"
#include <cmath>
#include <algorithm>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return std::abs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;        
        }
        return true;
    }

    int leastCommonMultiple(int a, int b)
    {
        int lcm = 1;
        int maxNum = std::max(a, b);
        for (int i = maxNum; i <= a * b; i += maxNum)
        {
            if (i % a == 0 && i % b == 0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
    }

    int GCD(int a, int b)
    {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }

    // 🔹 NEW: Implementation of thirdAngle
    double thirdAngle(double angleA, double angleB)
    {
        // angles must be positive and their sum must be < 180
        if (angleA <= 0.0 || angleB <= 0.0 || angleA + angleB >= 180.0)
        {
            throw std::invalid_argument("Invalid angles for a triangle");
        }
        return 180.0 - angleA - angleB;
    }
}
