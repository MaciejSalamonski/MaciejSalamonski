#include "addEven.hpp"
#include "gtest/gtest.h"

using AddEvenTuple = std::tuple<std::vector<int>, int>;
struct AddEven : public testing::TestWithParam<AddEvenTuple> {};

TEST_P(AddEven, CheckingIfSumOnlyConsistsOfEvenNumbers) {
    //GIVEN
    auto [vectorWithNumbers, expectedResultOfSum] = GetParam();
    //WHEN
    int sumOfVectorWithNumbers = addEven(std::vector<int>(vectorWithNumbers.begin(), vectorWithNumbers.end()));
    //THEN
    EXPECT_EQ(sumOfVectorWithNumbers, expectedResultOfSum);
}

INSTANTIATE_TEST_CASE_P(
    AddEvenTest,
    AddEven,
    ::testing::Values(
        AddEvenTuple{{}, {0}},
        AddEvenTuple{{1, 2, 3, 4, 5}, {6}},
        AddEvenTuple{{1, 1, 1, 1, 1, 1, 1}, {0}},
        AddEvenTuple{{2, 4, 6, 8}, {20}},
        AddEvenTuple{{0, 0, 0, 0, 0}, {0}},
        AddEvenTuple{{-2, -4, -6, -8, -10}, {-30}},
        AddEvenTuple{{2, -4, 6, -8}, {-4}},
        AddEvenTuple{{1, 2, 3}, {2}},
        AddEvenTuple{{2, 3, 4, 5, 2}, {8}},
        AddEvenTuple{{21, 20, 18, 16, 19}, {54}}));