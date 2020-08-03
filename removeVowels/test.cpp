#include "gtest/gtest.h"
#include "removeVowels.hpp"

TEST(RemoveVowelsTest, ShouldRemoveUppercaseVowels) {
    std::vector<std::string> vec{
        {"A"}, {"E"}, {"I"}, {"O"}, {"U"}, {"Y"}, {"AEIOUY"}};
    removeVowels(vec);
    ASSERT_EQ(vec.size(), 7);
    for (auto& str : vec) {
        EXPECT_TRUE(str.empty());
    }
}

TEST(RemoveVowelsTest, ShouldRemoveLowercaseVowels) {
    std::vector<std::string> vec{
        {"a"}, {"e"}, {"i"}, {"o"}, {"u"}, {"y"}, {"aeiouy"}};
    removeVowels(vec);
    ASSERT_EQ(vec.size(), 7);
    for (auto& str : vec) {
        EXPECT_TRUE(str.empty());
    }
}

TEST(RemoveVowelsTest, ShouldRemoveAllVowels) {
    std::vector<std::string> vec{
        {"Ala ma kota"},
        {"Alice has a cat"},
        {"Ala ma kota, a Sierotka Marysia"},
        {"ABCDERFGHIJK LMNOUPRS YYYY XXX ZZZ AAA BB CCC"},
        {"AaUuOoIiUuYy"}};
    removeVowels(vec);
    ASSERT_EQ(vec.size(), 5);
    EXPECT_EQ(vec[0], "l m kt");
    EXPECT_EQ(vec[1], "lc hs  ct");
    EXPECT_EQ(vec[2], "l m kt,  Srtk Mrs");
    EXPECT_EQ(vec[3], "BCDRFGHJK LMNPRS  XXX ZZZ  BB CCC");
    EXPECT_TRUE(vec[4].empty());
}

TEST(RemoveVowelTest, ShouldNotModify) {
    std::vector<std::string> vec{
        {"BRQW SXDFHJK PLTR"},
        {"QWRTP SDFGHJKL ZXCV BNM"},
        {"1234567890-=[],./\":\":\""},
        {"qzswdc rfvbgt hnmjk lp"}};
    std::vector<std::string> copy = vec;
    removeVowels(vec);

    ASSERT_EQ(vec.size(), 4);
    EXPECT_EQ(copy, vec);
}