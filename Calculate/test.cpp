#include <string>

#include "calculate.hpp"
#include "gtest/gtest.h"

using testTuple = std::tuple<std::string, std::pair<int, int>, std::string>;
struct calculateTestFixture : public testing::TestWithParam<testTuple> {};

TEST_P(calculateTestFixture, GivenAnInputComandAndPairOfNumbersShouldReturnExpectedResult) {
    //GIVEN
    auto [inputCommand, inputPairOfNumbers, expectedResult] = GetParam();

    //WHEN
    auto resultOfCalculation = calculate(inputCommand, inputPairOfNumbers.first, inputPairOfNumbers.second);

    //THEN
    ASSERT_EQ(resultOfCalculation, expectedResult);
}

INSTANTIATE_TEST_CASE_P(SomeCalculations,
                        calculateTestFixture,
                        testing::Values(
                            testTuple{{"add"}, {10, 20}, {"30"}},
                            testTuple{{"add"}, {15, 5}, {"20"}},
                            testTuple{{"add"}, {0, 0}, {"0"}},
                            testTuple{{"add"}, {1, -20}, {"-19"}},
                            testTuple{{"subtract"}, {10, 20}, {"-10"}},
                            testTuple{{"subtract"}, {15, 5}, {"10"}},
                            testTuple{{"subtract"}, {0, 0}, {"0"}},
                            testTuple{{"subtract"}, {1, -20}, {"21"}},
                            testTuple{{"multiply"}, {10, 20}, {"200"}},
                            testTuple{{"multiply"}, {15, 5}, {"75"}},
                            testTuple{{"multiply"}, {0, 0}, {"0"}},
                            testTuple{{"multiply"}, {1, -20}, {"-20"}},
                            testTuple{{"divide"}, {10, 20}, {"0"}},
                            testTuple{{"divide"}, {15, 5}, {"3"}},
                            testTuple{{"divide"}, {0, 0}, {"You can't divide by zero! Try again."}},
                            testTuple{{"divide"}, {-20, 10}, {"-2"}},
                            testTuple{{"quit"}, {10, 20}, {"Invalid data! Try again."}},
                            testTuple{{"q"}, {15, 5}, {"Invalid data! Try again."}},
                            testTuple{{"5"}, {0, 0}, {"Invalid data! Try again."}},
                            testTuple{{"sth"}, {1, -20}, {"Invalid data! Try again."}}));