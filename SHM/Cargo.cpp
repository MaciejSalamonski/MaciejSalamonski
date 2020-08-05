#include "Cargo.hpp"

#include <iostream>

Cargo::Cargo(const std::string& name, uint16_t amount, uint16_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {}

Cargo& Cargo::operator+=(uint16_t amountIncreasing) {
    amount_ += amountIncreasing;
    return *this;
}
Cargo& Cargo::operator-=(uint16_t amountDecreasing) {
    if (amount_ - amountDecreasing > amount_) {
        std::cerr << "Minimum amount of cargos is zero! You cannot throw any more of cargos overboar! Arghh";
        return *this;
    }
    amount_ -= amountDecreasing;
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return cargo.getAmount() == amount_ && cargo.getBasePrice() == basePrice_;
}

std::string Cargo::getName() const {
    return name_;
}
uint16_t Cargo::getAmount() const {
    return amount_;
}
uint16_t Cargo::getBasePrice() const {
    return basePrice_;
}