#include "Store.hpp"

std::string Store::getResponseMessage(const Response responseMassage) {
    switch (responseMassage) {
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

Response buy(Cargo* cargo, uint16_t amount, Player* player) {
}