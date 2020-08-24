#pragma once

#include "Ship.hpp"

class Player {
    uint16_t money_;
    Ship* ship_;
    uint16_t availableSpace_;

public:
    Player(uint16_t, Ship*, uint16_t);

    uint16_t GetAvailableSpace() const { return availableSpace_; }
    uint16_t GetMoney() const { return money_; }
    uint16_t GetSpeed() const { return ship_->GetSpeed(); }

    Cargo* GetCargo(uint16_t) const;
    void PurchaseCargo(std::unique_ptr<Cargo>, uint16_t);
    void SellCargo(Cargo*, uint16_t);
};