#pragma once

#include <cmath>
#include <string>

class Cargo {
protected:
    uint16_t amount_;
    std::string name_;
    uint16_t basePrice_;

public:
    Cargo() = default;
    Cargo(uint16_t, const std::string&, uint16_t);
    virtual uint16_t GetPrice() const = 0;
    virtual std::string GetName() const = 0;
    virtual uint16_t GetAmount() const = 0;
    virtual uint16_t GetBasePrice() const = 0;
    virtual Cargo& operator+=(uint16_t) = 0;
    virtual Cargo& operator-=(uint16_t) = 0;
    virtual bool operator==(const Cargo&) const = 0;
};