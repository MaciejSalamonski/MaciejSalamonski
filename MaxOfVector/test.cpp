#include "gtest/gtest.h"

#include "maxOfVector.hpp"

using paramTuple = std::tuple<std::vector<int>, int>; 
struct MaxOfVector : public ::testing::TestWithParam<paramTuple> {};

TEST_P(MaxOfVector, FunctionMaxOfVectorShouldGivenNumberWithMaxValueEqualToExpectedValue){
    //GIVEN
    auto [vectorWithNumbers, expectedResult] = GetParam();
    //WHEN
    int maxValueOfVector = maxOfVector(vectorWithNumbers);
    //THEN
    EXPECT_EQ(maxValueOfVector, expectedResult);
}

INSTANTIATE_TEST_CASE_P(
    MaxOfVectorTests,
    MaxOfVector, 
    ::testing::Values(
        paramTuple{{1, 2, 3, 4, 5}, 5},
        paramTuple{{100, 1, -5}, 100},
        paramTuple{{1337, 2137, 69, 1939, 1945}, 2137},
        paramTuple{{-5, -23, -54, -2, -1}, -1},
        paramTuple{{0, 0, 0, 0}, 0},
        paramTuple{{1, 2, 5, 4, 5, 8, 9, 6, 4, 2, 1, 2, 5}, 9},
        paramTuple{{1, -2}, 1},
        paramTuple{{5, 3}, 5},
        paramTuple{{0}, 0},
        paramTuple{{1, -54, 213, 0, 1}, 213}
    )
);