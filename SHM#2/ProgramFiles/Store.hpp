#pragma once

#include "Player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store {
    Response buy(Cargo*, uint16_t, Player*);
    Response sell(Cargo*, uint16_t, Player*);
    std::string getResponseMessage(const Response);
};