#include "maxOfVector.hpp"

#include <algorithm>

int maxOfVector(const std::vector<int>& vec) {
    return *std::max_element(vec.begin(), vec.end());
}