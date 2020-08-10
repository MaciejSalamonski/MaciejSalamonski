#include "Store.hpp"

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

void Store::generateCargo() {
    cargos_ = {
        std::make_shared<Alcohol>(Alcohol(0, "Vodka", 30, 40)),
        std::make_shared<Alcohol>(Alcohol(0, "Rum", 50, 70)),
        std::make_shared<Alcohol>(Alcohol(0, "Whisky", 35, 45)),
        std::make_shared<Alcohol>(Alcohol(0, "Beer", 5, 7)),
        std::make_shared<Alcohol>(Alcohol(0, "Panoramix cauldron", 100, 90)),
        std::make_shared<Fruit>(Fruit(0, "Apple", 15, 14)),
        std::make_shared<Fruit>(Fruit(0, "Dried plums", 100, 100)),
        std::make_shared<Fruit>(Fruit(0, "Strawberries", 4, 6)),
        std::make_shared<Fruit>(Fruit(0, "Peach", 8, 10)),
        std::make_shared<Fruit>(Fruit(0, "Cherry", 12, 12)),
        std::make_shared<Item>(Item(0, "Knife", 25, Rarity::rare)),
        std::make_shared<Item>(Item(0, "Bottle", 10, Rarity::common)),
        std::make_shared<Item>(Item(0, "Sword", 70, Rarity::epic)),
        std::make_shared<Item>(Item(0, "Golden Necklace", 200, Rarity::legendary)),
        std::make_shared<Item>(Item(0, "Compass", 90, Rarity::epic))};
}

Cargo* Store::findMatchCargo(Cargo*) {
}

void Store::removeFromStore(Cargo*) {
}

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
