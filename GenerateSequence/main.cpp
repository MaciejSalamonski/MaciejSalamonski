#include "generateSequence.hpp"

#include <iostream>

int main() {
    for(const auto el : generateSequence(5,3)) {
        std::cout << el << " | ";
    }

    return 0;
}