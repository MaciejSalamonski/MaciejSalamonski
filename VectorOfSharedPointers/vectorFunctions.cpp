#include "vectorFunctions.hpp"

constexpr const int vectorSizeCannotBeANegativeNumber = 0;

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec;
    if (count < vectorSizeCannotBeANegativeNumber) {
        return vec;
    }
    vec.reserve(count);
    for (int i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<int>(i));
    }

    return vec;
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        std::cout << *el << '\n';
    }
}

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        *el += 10;
    }
}

void sub10(int* const ptr) {
    if (ptr) {
        *ptr -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        sub10(el.get());
    }
}