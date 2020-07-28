#include "generateSequence.hpp"
#include "gtest/gtest.h"

struct TestParameters {
    int count;
    int step;
    std::vector<int> expectedVector;
};

struct GenerateSequence : public ::testing::TestWithParam<TestParameters> {};

TEST_P(GenerateSequence, ShouldGiveAVectorWithSpecifySequenceThatIsEqualToExpectedVector){
    //GIVEN
    const TestParameters& testParameters = GetParam();

    //WHEN
    std::vector<int> vectorWithSpecifySequence = generateSequence(testParameters.count, testParameters.step);

    //THEN
    EXPECT_EQ(vectorWithSpecifySequence, testParameters.expectedVector);
}

INSTANTIATE_TEST_CASE_P (
    GenerateSequenceTest,
    GenerateSequence, 
    ::testing::Values(
        TestParameters{5, 3, {3, 6, 9, 12, 15}},
        TestParameters{3, 1, {1, 2, 3}},
        TestParameters{0, 10, {}},
        TestParameters{-1, 3, {}},
        TestParameters{-30, 5, {}},
        TestParameters{7, 2, {2, 4, 6, 8, 10, 12, 14}},
        TestParameters{6, -6, {-6, -12, -18, -24, -30, -36}},
        TestParameters{5, 1, {1, 2, 3, 4, 5}},
        TestParameters{4, -3, {-3, -6, -9, -12}},
        TestParameters{1, 0, {0}},
        TestParameters{5, 0, {0, 0, 0, 0, 0}},
        TestParameters{6, 3, {3, 6, 9, 12, 15, 18}}
    )
);