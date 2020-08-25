#pragma once

#include "Cargo.hpp"

namespace {
constexpr uint8_t MAX_ALCOHOL_POWER = 96;
}

class Alcohol : public Cargo {
    uint8_t percentage_;

public:
    Alcohol(uint16_t, const std::string&, uint16_t, uint8_t);
    ~Alcohol() = default;
    uint8_t GetPercentage() const { return percentage_; }

    //Override from Cargo
    uint16_t GetPrice() const override;
    std::string GetName() const override { return name_; }
    uint16_t GetAmount() const override { return amount_; }
    uint16_t GetBasePrice() const override { return basePrice_; }
    Cargo& operator+=(uint16_t) override;
    Cargo& operator-=(uint16_t) override;
    bool operator==(const Cargo&) const override;

    //Override from Observer
    void NextDay() override {}
};