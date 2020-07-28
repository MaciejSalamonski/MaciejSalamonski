#include "addEven.hpp"

int addEven(const std::vector<int>& vec) {
    int sum{};

    for (const auto& el : vec) {
        if (el % 2 == 0) {
            sum += el;
        }
    }

    return sum;
}