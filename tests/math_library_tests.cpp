#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest/gtest.h>
#include <fstream>
#include "math_lib.h"

class MathLibTestFixture : public ::testing::Test
{
protected:

    void SetUp() override
    {
        // Do some job before test run
    }

    void TearDown() override
    {
        // Do some job after test run
    }
};

TEST_F(MathLibTestFixture, AddTwoValues)
{
    EXPECT_EQ(MathLib::add(10.5, 2.5), 13.0);
    EXPECT_TRUE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0));
    EXPECT_FALSE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0001));
}

TEST_F(MathLibTestFixture, SubTwoValues)
{
    EXPECT_NE(MathLib::subtract(10, 7), 4);
    EXPECT_EQ(MathLib::subtract(10, 7), 3);
}

TEST_F(MathLibTestFixture, MultiplyTwoValues)
{
    EXPECT_EQ(MathLib::multiply(10, 7), 70);
    EXPECT_NE(MathLib::multiply(10, 7), 71);
}

TEST_F(MathLibTestFixture, DivideTwoValues)
{
    EXPECT_EQ(MathLib::divide(10, 2), 5);
    EXPECT_NE(MathLib::divide(10, 2), 3);
}

TEST_F(MathLibTestFixture, DivideByZero)
{
    EXPECT_THROW(MathLib::divide(10, 0), std::invalid_argument);
}

TEST_F(MathLibTestFixture, SquareRoot)
{
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(0), 0));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(1.231), 1.1095));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(16), 4));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(123), 11.0905));
    EXPECT_THROW(MathLib::sqrt(-1), std::invalid_argument);
}

TEST_F(MathLibTestFixture, LeastCommonMultiple)
{
    EXPECT_EQ(MathLib::leastCommonMultiple(4, 6), 12);
    EXPECT_EQ(MathLib::leastCommonMultiple(7, 5), 35);
    EXPECT_EQ(MathLib::leastCommonMultiple(10, 5), 10);
    EXPECT_NE(MathLib::leastCommonMultiple(4, 6), 3);
}

TEST_F(MathLibTestFixture, IsPrimeTest)
{
    EXPECT_TRUE(MathLib::isPrime(2));
    EXPECT_TRUE(MathLib::isPrime(3));
    EXPECT_FALSE(MathLib::isPrime(4));
    EXPECT_TRUE(MathLib::isPrime(5));
}

TEST_F(MathLibTestFixture, GreatestCommonDivider)
{
    EXPECT_EQ(MathLib::GCD(10, 6), 2);
}

// 🔹 NEW TESTS: thirdAngle

TEST_F(MathLibTestFixture, ThirdAngleValid)
{
    EXPECT_TRUE(MathLib::isEqual(MathLib::thirdAngle(60.0, 60.0), 60.0));
    EXPECT_TRUE(MathLib::isEqual(MathLib::thirdAngle(30.0, 90.0), 60.0));
    EXPECT_TRUE(MathLib::isEqual(MathLib::thirdAngle(45.0, 45.0), 90.0));
}

TEST_F(MathLibTestFixture, ThirdAngleInvalid)
{
    // zero angle
    EXPECT_THROW(MathLib::thirdAngle(0.0, 60.0), std::invalid_argument);
    // negative angle
    EXPECT_THROW(MathLib::thirdAngle(-10.0, 60.0), std::invalid_argument);
    // sum >= 180
    EXPECT_THROW(MathLib::thirdAngle(120.0, 70.0), std::invalid_argument);
}
