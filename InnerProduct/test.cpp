#include <cmath>
#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 2.875));
    // Write more test case
}

TEST(arithmeticAverageTest, ShouldntCalculateArithmeticAverageWhenDenominatorIsNull) {
    std::vector<int> first{};
    std::vector<int> second{};
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 0));
}

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverageWhenVectorsSizeIsNotTheSame) {
    std::vector<int> first{1, 2, 3, 4, 7};
    std::vector<int> second{1, 2, 3, 4};
    EXPECT_TRUE((ArithmeticAverage(first, second), 3));
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance(first, second), 10.247));
    // Write more test case
}

TEST(arithmeticAverageTest, ShouldntCalculateDistanceWhenVectorsSizeIsNotTheSame) {
    std::vector<int> first{7, 4};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance(first, second), 0));
}

TEST(arithmeticAverageTest, ShouldCalculateDistanceForTheSameCoordinates) {
    std::vector<int> first{0, 0};
    std::vector<int> second{0, 0};
    EXPECT_TRUE(cmp(Distance(first, second), 0));
}