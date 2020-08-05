#include "gtest/gtest.h"
#include "transformContainerToMap.hpp"

TEST(TransformContainerToMapTest, ShouldReturnUniqueMap) {
    std::map<int, std::string> expectedResult{
        {0, "Baton"},
        {1, "Ciastko"},
        {2, "Makowiec"},
        {3, "Piernik"},
        {4, "Sernik"},
        {5, "Tort"}};
    std::list<std::string> listWithStrings{
        "Piernik", "Piernik", "Tort", "Sernik", "Piernik",
        "Tort", "Makowiec", "Baton", "Makowiec", "Ciastko"};
    std::deque<int> dequeWithNumbers{
        0, 1, 1, 1, 2, 3, 5, 1, 2, 3, 4, 4, 2,
        0, 0, 0, 1, 2, 3, 4, 5, 1, 2, 2, 3, 0};

    std::map<int, std::string> result = removeDuplicateAndTranformToMap(listWithStrings, dequeWithNumbers);

    ASSERT_TRUE(result.size() == expectedResult.size());
    EXPECT_TRUE(std::equal(result.begin(), result.end(),
                           expectedResult.begin(),
                           [](const auto& resultParam, const auto& expectedParam) {
                               return resultParam.first == expectedParam.first && resultParam.second == expectedParam.second;
                           }));
}