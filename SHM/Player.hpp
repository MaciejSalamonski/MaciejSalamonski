#pragma once

#include <memory>

#include "Ship.hpp"

class Player {
    std::shared_ptr<Ship> ship_;
    uint16_t money_;
    uint16_t availableSpace_;

public:
    Player() = default;
    Player(std::shared_ptr<Ship>, uint16_t, uint16_t);
    uint16_t getMoney() const;
    uint16_t getAvailableSpace() const;
    uint16_t getSpeed() const;
    Cargo* getCargo(uint16_t index) const;
    void updateAvailableSpace();
};