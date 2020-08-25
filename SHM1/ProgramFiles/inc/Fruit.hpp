#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
    uint8_t timeElapsed_;
    uint8_t expiryDate_;

public:
    Fruit(uint16_t, const std::string&, uint16_t, uint8_t, uint8_t);
    ~Fruit() = default;

    Fruit& operator--();

    uint8_t GetTimeElapsed() const { return timeElapsed_; }
    uint8_t GetExpiryDate() const { return expiryDate_; }

    //Override from Cargo
    uint16_t GetPrice() const override;
    std::string GetName() const override { return name_; }
    uint16_t GetAmount() const override { return amount_; }
    uint16_t GetBasePrice() const override { return basePrice_; }
    Cargo& operator+=(uint16_t) override;
    Cargo& operator-=(uint16_t) override;
    bool operator==(const Cargo&) const override;

    //Override from Observer
    void NextDay() override;
};