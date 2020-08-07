#pragma once

#include <vector>

#include "Island.hpp"

class Map {
    std::vector<Island> islands_;
    Island* currentPosition_;

public:
    Map();
    Island* getIsland(const Coordinates&);
};