#pragma once

#include <vector>

#include "Island.hpp"

namespace {
    constexpr uint16_t NUMBER_OF_ISLANDS = 10;
    constexpr uint16_t MAX_VALUE_OF_AXIS_X = 100;
    constexpr uint16_t MAX_VALUE_OF_AXIS_Y = 100;
}  

class Map {
    Island* currentPosition_;
    std::vector<Island> islands_;

public:
    Map();
    uint16_t GetDistanceToIsland(Island*) const;
    Island* GetIsland(const Coordinates&);
    Island* GetCurrentPosition() const;
};