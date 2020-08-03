#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "vectorFunctions.hpp"

constexpr const int count = 10;

struct VectorOfSharedPointersTest : public testing::Test {
    std::vector<std::shared_ptr<int>> generateExpectedVector(const int count) {
        std::vector<std::shared_ptr<int>> expectedVector;
        expectedVector.reserve(count);
        for (size_t i = 0; i < count; ++i) {
            expectedVector.emplace_back(std::make_shared<int>(i));
        }

        return expectedVector;
    }
};

TEST_F(VectorOfSharedPointersTest, ShouldGenerateProperVectorWithProperSize) {
    std::vector<std::shared_ptr<int>> expectedVector = generateExpectedVector(count);
    std::vector<std::shared_ptr<int>> resultVector = generate(count);

    ASSERT_EQ(resultVector.size(), expectedVector.size());
    for (size_t i = 0; i < count; ++i) {
        EXPECT_EQ(*resultVector[i], i);
    }
}

TEST_F(VectorOfSharedPointersTest, ShouldAddTenToEachElementOfVector) {
    std::vector<std::shared_ptr<int>> resultVector = generate(count);
    add10(resultVector);

    for (size_t i = 0; i < count; ++i) {
        EXPECT_EQ(*resultVector[i], i + 10);
    }
}

TEST_F(VectorOfSharedPointersTest, ShouldSubtractThenForPtr) {
    auto ptr = std::make_shared<int>(10);
    sub10(ptr.get());
    ASSERT_TRUE(ptr);
    EXPECT_EQ(*ptr, 0);
}

TEST_F(VectorOfSharedPointersTest, BehavioralTest) {
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.emplace_back(std::make_shared<int>(i + 10));
    }

    std::vector<std::shared_ptr<int>> copyVec = vec;
    sub10(vec);
    add10(vec);
    EXPECT_EQ(copyVec, vec);
    for (size_t i = 0; i < count; ++i) {
        EXPECT_EQ(vec[i], copyVec[i]);
    }
}

TEST_F(VectorOfSharedPointersTest, ShouldntSubtractForNullptr) {
    int* ptr = nullptr;
    sub10(ptr);
    EXPECT_EQ(ptr, nullptr);
}

TEST_F(VectorOfSharedPointersTest, ShouldSubtractTenToEachElementOfVector) {
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.emplace_back(std::make_shared<int>(i + 10));
    }
    sub10(vec);

    for (size_t i = 0; i < count; ++i) {
        EXPECT_EQ(*vec[i], i);
    }
}
