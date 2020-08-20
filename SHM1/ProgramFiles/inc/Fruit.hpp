#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
    uint16_t timeElapsed_;
    uint16_t expiryDate_;

public:
    Fruit(uint16_t, const std::string&, uint16_t, uint16_t, uint16_t);
    ~Fruit() = default;
    uint16_t GetTimeElapsed() const;
    uint16_t GetExpiryDate() const;

    //Override from Cargo
    uint16_t GetPrice() const override;
    std::string GetName() const override;
    uint16_t GetAmount() const override;
    uint16_t GetBasePrice() const override;
    Cargo& operator+=(uint16_t) override;
    Cargo& operator-=(uint16_t) override;
    bool operator==(const Cargo&) const override;
};