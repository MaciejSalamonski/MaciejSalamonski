#include "gtest/gtest.h"
#include "sort.hpp"

TEST(LengthSortTests, ShouldSortLexicographicallyWhenLengthIsEqual) {
    std::forward_list<std::string> list{
        {"QWERTY"},
        {"QAZWSX"},
        {"TOMASZ"},
        {"ALICJA"},
        {"STHLAL"},
        {"WORDSS"},
        {"SWORDS"}};
    std::deque<std::string> expectedResult{
        {"alicja"},
        {"qazwsx"},
        {"qwerty"},
        {"sthlal"},
        {"swords"},
        {"tomasz"},
        {"wordss"}};
    std::deque<std::string> result = lengthSort(list);
    ASSERT_TRUE(result.size() == expectedResult.size());
    EXPECT_EQ(result, expectedResult);
}

TEST(LengthSortTests, ShouldSortByLength) {
    std::forward_list<std::string> list{
        {"alamakota"},
        {"ala"},
        {"alam"},
        {"alamakot"},
        {"a"},
        {"alama"},
        {"alamak"},
        {"alamako"},
        {"al"}};
    std::deque<std::string> expectedResult{
        {"a"},
        {"al"},
        {"ala"},
        {"alam"},
        {"alama"},
        {"alamak"},
        {"alamako"},
        {"alamakot"},
        {"alamakota"}};
    std::deque<std::string> result = lengthSort(list);
    ASSERT_TRUE(result.size() == expectedResult.size());
    EXPECT_EQ(result, expectedResult);
}