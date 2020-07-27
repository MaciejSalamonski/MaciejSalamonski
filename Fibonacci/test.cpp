#include "fibonacci.hpp"
#include "gtest/gtest.h"
/*
TEST(FibonacciTest, GivenAnInputNumberOfSequenceShouldBeEqualToExpectedFibonacciIterativeFunctionResult) {
    EXPECT_EQ(fibonacci_iterative(0), 0);
    EXPECT_EQ(fibonacci_iterative(1), 1);
    EXPECT_EQ(fibonacci_iterative(-1), 0);
    EXPECT_EQ(fibonacci_iterative(2), 1);
    EXPECT_EQ(fibonacci_iterative(3), 2);
    EXPECT_EQ(fibonacci_iterative(5), 5);
    EXPECT_EQ(fibonacci_iterative(10), 55);
    EXPECT_EQ(fibonacci_iterative(33), 3524578);
}

TEST(FibonacciTest, GivenAnInputNumberOfSequenceShouldBeEqualToExpectedFibonacciRecursiveFunctionResult) {
    EXPECT_EQ(fibonacci_recursive(0), 0);
    EXPECT_EQ(fibonacci_recursive(1), 1);
    EXPECT_EQ(fibonacci_recursive(-1), 0);
    EXPECT_EQ(fibonacci_recursive(2), 1);
    EXPECT_EQ(fibonacci_recursive(3), 2);
    EXPECT_EQ(fibonacci_recursive(5), 5);
    EXPECT_EQ(fibonacci_recursive(10), 55);
    EXPECT_EQ(fibonacci_recursive(33), 3524578);
}*/

using testParameters = std::tuple<int, int>;
struct Fibonacci : public testing::TestWithParam<testParameters> {};

TEST_P(Fibonacci, ShouldCalculateFibonacciIteratively) {
    //GIVEN
    auto [sequence, expectedResult] = GetParam();
    //WHEN
    int fibonacciResultOfUserInput = fibonacci_iterative(sequence);
    //THEN
    EXPECT_EQ(fibonacciResultOfUserInput, expectedResult);
}

TEST_P(Fibonacci, ShouldCalculateFibonacciRecursively) {
    //GIVEN
    auto [sequence, expectedResult] = GetParam();
    //WHEN
    int fibonacciResultOfUserInput = fibonacci_recursive(sequence);
    //THEN
    EXPECT_EQ(fibonacciResultOfUserInput, expectedResult);
}

INSTANTIATE_TEST_CASE_P(
    FibonacciTest,
    Fibonacci, 
    ::testing::Values(
    std::make_tuple(10, 55), 
    std::make_tuple(0, 0),  
    std::make_tuple(1, 1), 
    std::make_tuple(2, 1),
    std::make_tuple(3, 2), 
    std::make_tuple(4, 3), 
    std::make_tuple(5, 5), 
    std::make_tuple(6, 8),
    std::make_tuple(13, 233), 
    std::make_tuple(17, 1597),
    std::make_tuple(20, 6765), 
    std::make_tuple(-20, 0)));
