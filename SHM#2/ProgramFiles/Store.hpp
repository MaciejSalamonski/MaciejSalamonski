#pragma once

#include "Cargo.hpp"
#include "Player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store {
    std::vector<std::shared_ptr<Cargo>> cargos_;

public:
    Store() = default;
    Cargo* getCargo(const uint16_t) const;
    Response buy(Cargo*, uint16_t, Player*);
    Response sell(Cargo*, uint16_t, Player*);
    std::string getResponseMessage(const Response);
};