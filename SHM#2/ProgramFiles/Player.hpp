#pragma once

#include <memory>

#include "Delegate.hpp"
#include "Ship.hpp"

class Player : public Delegate {
    std::shared_ptr<Ship> ship_;
    uint16_t money_;
    uint16_t availableSpace_;

    void updateAvailableSpace();

public:
    Player() = default;
    Player(std::shared_ptr<Ship>, uint16_t, uint16_t);

    std::shared_ptr<Ship> getShip() const;
    uint16_t getMoney() const;
    uint16_t getAvailableSpace() const;
    uint16_t getSpeed() const;
    Cargo* getCargo(uint16_t) const;
    Cargo* getCargos() const;

    void payCrew(uint16_t) override;
};