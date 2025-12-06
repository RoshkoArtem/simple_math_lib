#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest/gtest.h>
#include "math_lib.h"
#include <cmath>

class MathLibTestFixture : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(MathLibTestFixture, AddTwoValues)
{
    EXPECT_NEAR(MathLib::add(10.5, 2.5), 13.0, 1e-9);
    EXPECT_TRUE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0));
    EXPECT_FALSE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0001));
}

TEST_F(MathLibTestFixture, SubTwoValues)
{
    EXPECT_EQ(MathLib::subtract(10, 7), 3);
    EXPECT_NE(MathLib::subtract(10, 7), 4);
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
    EXPECT_THROW(MathLib::sqrt(-1), std::invalid_argument);
}

TEST_F(MathLibTestFixture, LeastCommonMultiple)
{
    EXPECT_EQ(MathLib::leastCommonMultiple(4, 6), 12);
    EXPECT_EQ(MathLib::leastCommonMultiple(7, 5), 35);
    EXPECT_EQ(MathLib::leastCommonMultiple(10, 5), 10);
    EXPECT_NE(MathLib::leastCommonMultiple(4,6), 3);
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

TEST(ThirdAngleTest, BasicCalculation)
{
    EXPECT_NEAR(MathLib::thirdAngle(30.0, 60.0), 90.0, 1e-3);
    EXPECT_NEAR(MathLib::thirdAngle(10.0, 10.0), 160.0, 1e-3);
}

TEST(ThirdAngleTest, InvalidInput)
{
    EXPECT_THROW(MathLib::thirdAngle(100.0, 90.0), std::invalid_argument);
    EXPECT_THROW(MathLib::thirdAngle(-1.0, 10.0), std::invalid_argument);
}