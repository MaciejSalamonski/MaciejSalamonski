#pragma once

#include "Cargo.hpp"

namespace {
constexpr uint16_t MAX_ALCOHOL_POWER = 96;
}

class Alcohol : public Cargo {
    uint16_t percentage_;

public:
    Alcohol(uint16_t, const std::string&, uint16_t, uint16_t);
    ~Alcohol() = default;
    uint16_t GetPercentage() const;

    //Override from Cargo
    uint16_t GetPrice() const override;
    std::string GetName() const override;
    uint16_t GetAmount() const override;
    uint16_t GetBasePrice() const override;
    Cargo& operator+=(uint16_t) override;
    Cargo& operator-=(uint16_t) override;
    bool operator==(const Cargo&) const override;
};