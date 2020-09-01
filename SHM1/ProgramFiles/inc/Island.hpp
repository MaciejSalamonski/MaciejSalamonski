#pragma once

#include "Coordinates.hpp"
#include "Store.hpp"

class Island {
    Coordinates position_;
    Store* store_;

public:
    Island(uint8_t, uint8_t);
    Coordinates GetCoordinates() const { return position_; }
    Store* GetStore() const { return store_; }
};