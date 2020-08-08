#include "Store.hpp"

Cargo* Store::getCargo(const uint16_t index) const {
    return cargos_[index].get();
}

std::string getResponseMessage(const Response responseMessage) {
    switch (responseMessage) {
    case Response::done:
        return "Done!";
    case Response::lack_of_cargo:
        return "Lack of cargo!";
    case Response::lack_of_money:
        return "Lack of money!";
    case Response::lack_of_space:
        return "Lack of space!";
    }
}

Response Store::buy(Cargo* cargo, uint16_t amount, Player* player) {
    if (cargo) {
        // uint16_t price = (cargo->getName())->get;
    }
}