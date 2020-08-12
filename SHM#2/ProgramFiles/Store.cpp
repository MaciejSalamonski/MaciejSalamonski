#include "Store.hpp"

#include <algorithm>
#include <iterator>
#include <random>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Store.hpp"

void Store::generateCargo() {
    std::vector<std::shared_ptr<Cargo>> generateCargos{
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

std::vector<std::shared_ptr<Cargo>>::iterator Store::findMatchCargo(Cargo* cargo) {
    if (cargo) {
        auto findCargo = std::find_if(cargos_.begin(), cargos_.end(),
                                      [cargo](const auto& el) {
                                          return cargo->getBasePrice() == el->getBasePrice() &&
                                                 cargo->getPrice() == el->getPrice() &&
                                                 cargo->getName() == el->getName();
                                      });

        return findCargo;
    }
}

void Store::removeFromStore(Cargo* cargo) {
    cargos_.erase(findMatchCargo(cargo));
}

void load(std::shared_ptr<Cargo> cargo) {
}

void unload(Cargo* cargo) {
}

Cargo* Store::getCargo(const uint16_t index) const {
    return cargos_[index].get();
}

std::string getResponseMessage(const Response& responseMessage) {
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
