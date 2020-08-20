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
    Rarity GetRarity() const;

    //Override from Cargo
    uint16_t GetPrice() const override;
    std::string GetName() const override;
    uint16_t GetAmount() const override;
    uint16_t GetBasePrice() const override;
    Cargo& operator+=(uint16_t) override;
    Cargo& operator-=(uint16_t) override;
    bool operator==(const Cargo&) const override;
};