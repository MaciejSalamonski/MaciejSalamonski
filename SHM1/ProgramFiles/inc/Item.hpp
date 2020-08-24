#pragma once

#include "Cargo.hpp"

enum class Rarity {
    common = 1,
    rare = 3,
    epic = 7,
    legendary = 15
};

class Item : public Cargo {
    Rarity rarity_;

public:
    Item(uint16_t, const std::string&, uint16_t, Rarity);
    ~Item() = default;
    Rarity GetRarity() const { return rarity_; }

    //Override from Cargo
    uint16_t GetPrice() const override;
    std::string GetName() const override { return name_; }
    uint16_t GetAmount() const override { return amount_; }
    uint16_t GetBasePrice() const override { return basePrice_; }
    Cargo& operator+=(uint16_t) override;
    Cargo& operator-=(uint16_t) override;
    bool operator==(const Cargo&) const override;
};