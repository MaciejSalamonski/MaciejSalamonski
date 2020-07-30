#include "gtest/gtest.h"
#include "nwdNww.hpp"

using testParameters = std::tuple<int, int, int>;
struct FunctionNwd : public ::testing::TestWithParam<testParameters> {};

TEST_P(FunctionNwd, functionThatCalculateTheGreatestCommonDivisiorShouldBeGivenAResultEqualToExpectedResult) {
    //GIVEN
    auto [lhs, rhs, expectedResult] = GetParam();
    //WHEN
    int result = NWD(lhs, rhs);
    //THEN
    EXPECT_EQ (result, expectedResult);
}

INSTANTIATE_TEST_CASE_P(
    FunctionNwdTest, 
    FunctionNwd, 
    ::testing::Values(
        testParameters{10, 10, 10},
        testParameters{44, 123, 1},
        testParameters{123, 44, 1},
        testParameters{891, 33, 33},
        testParameters{23122, 322, 2},
        testParameters{4345, 25, 5},
        testParameters{65464, 344324, 4},
        testParameters{2, 2, 2},
        testParameters{1, 1, 1},
        testParameters{1, 0, 1},
        testParameters{0, 1, 1},
        testParameters{0, 10, 10},
        testParameters{0, 0, 0},
        testParameters{-10, -2, 2},
        testParameters{-10, 2, 2},
        testParameters{10, -2, 2}
    )
);

struct FunctionNww : public ::testing::TestWithParam<testParameters> {};

TEST_P(FunctionNww, functionThatCalculateLowestCommonMultipleShouldBeGivenResultEqualToExpectedResult) {
    //GIVEN
    auto [lhs, rhs, expectedResult] = GetParam();
    //WHEN
    int result = NWW(lhs, rhs);
    //THEN
    EXPECT_EQ (result, expectedResult);
}

INSTANTIATE_TEST_CASE_P(
    FunctionNwwTest, 
    FunctionNww, 
    ::testing::Values(
        testParameters{24, 36, 72},
        testParameters{50, 17, 850},
        testParameters{50, 30, 150},
        testParameters{23122, 322, 3722642},
        testParameters{28, 14, 28},
        testParameters{105, 25, 525},
        testParameters{0, 0, 0},
        testParameters{1, 0, 0},
        testParameters{0, 1, 0},
        testParameters{0, -2, 0},
        testParameters{1, 1, 1},
        testParameters{-1, 1, 1},
        testParameters{1, -1, 1},
        testParameters{-1, -1, 1},
        testParameters{-10, -10, 10},
        testParameters{-10, -2, 10}
    )
);