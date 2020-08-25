#pragma once

#include <memory>
#include <vector>

#include "Cargo.hpp"

class Ship {
    uint16_t capacity_;
    uint16_t crew_;
    uint16_t speed_;
    std::string name_;
    uint16_t id_;
    std::vector<std::unique_ptr<Cargo>> cargo_;

    std::vector<std::unique_ptr<Cargo>>::iterator FindMatchCargo(Cargo*);
    void RemoveFromStorage(Cargo*);

public:
    Ship(uint16_t, uint16_t, uint16_t, const std::string&, uint16_t);

    void Load(std::unique_ptr<Cargo>);
    void Unload(std::unique_ptr<Cargo>);

    uint16_t GetCapacity() const { return capacity_; }
    uint16_t GetCrew() const { return crew_; }
    uint16_t GetSpeed() const { return speed_; }
    std::string GetName() const { return name_; }
    uint16_t GetId() const { return id_; }

    Cargo* GetCargo(uint16_t) const;
};