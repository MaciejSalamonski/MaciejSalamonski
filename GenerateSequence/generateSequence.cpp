#include "generateSequence.hpp"

constexpr int minSizeOfSequence = 0;

std::vector<int> generateSequence(const int count, const int step) {
    std::vector<int> vecWithSequence{};

    if (count > minSizeOfSequence) {
        vecWithSequence.reserve(count);
        for (int i = 0; i != count; i++) {
            vecWithSequence.push_back(step * (i + 1));
        }
        return vecWithSequence;
    } 
    else {
        return {};
    }
}