#include "Store.hpp"

#include <algorithm>
#include <random>

#include "Alcohol.hpp"
#include "Cargo.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Player.hpp"

void Store::GenerateCargo() {
    std::vector<std::unique_ptr<Cargo>> possibleCargo;
    possibleCargo.reserve(NUMBER_OF_ITEMS);

    possibleCargo.push_back(std::make_unique<Alcohol>(Alcohol(0, "Vodka", 30, 40)));
    possibleCargo.push_back(std::make_unique<Alcohol>(Alcohol(0, "Rum", 50, 70)));
    possibleCargo.push_back(std::make_unique<Alcohol>(Alcohol(0, "Whisky", 35, 45)));
    possibleCargo.push_back(std::make_unique<Alcohol>(Alcohol(0, "Beer", 5, 7)));
    possibleCargo.push_back(std::make_unique<Alcohol>(Alcohol(0, "Panoramix cauldron", 100, 90)));
    possibleCargo.push_back(std::make_unique<Fruit>(Fruit(0, "Apple", 15, 14, 1)));
    possibleCargo.push_back(std::make_unique<Fruit>(Fruit(0, "Dried plum", 100, 100, 1)));
    possibleCargo.push_back(std::make_unique<Fruit>(Fruit(0, "Strawberry", 4, 6, 1)));
    possibleCargo.push_back(std::make_unique<Fruit>(Fruit(0, "Peach", 8, 10, 1)));
    possibleCargo.push_back(std::make_unique<Fruit>(Fruit(0, "Cherry", 12, 12, 1)));
    possibleCargo.push_back(std::make_unique<Item>(Item(0, "Bottle", 10, Rarity::common)));
    possibleCargo.push_back(std::make_unique<Item>(Item(0, "Knife", 25, Rarity::rare)));
    possibleCargo.push_back(std::make_unique<Item>(Item(0, "Sword", 70, Rarity::epic)));
    possibleCargo.push_back(std::make_unique<Item>(Item(0, "Compass", 90, Rarity::epic)));
    possibleCargo.push_back(std::make_unique<Item>(Item(0, "Golden Necklace", 200, Rarity::legendary)));

    RandomizeCargo(possibleCargo);
}

void Store::RandomizeCargo(std::vector<std::unique_ptr<Cargo>>& possibleCargo) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomAmount(MIN_RANDOM_AMOUNT, MAX_RANDOM_AMOUNT);

    for (auto& cargo : possibleCargo) {
        *cargo += randomAmount(gen);
        storeCargo_.push_back(std::move(cargo));
    }
}

std::vector<std::unique_ptr<Cargo>>::iterator Store::FindMatchCargo(Cargo* cargo) {
    auto findMatchCargo = std::find_if(storeCargo_.begin(), storeCargo_.end(),
                                       [cargo](const auto& findCargo) {
                                           return cargo->GetName() == findCargo->GetName() &&
                                                  cargo->GetPrice() == findCargo->GetPrice() &&
                                                  cargo->GetBasePrice() == findCargo->GetBasePrice();
                                       });

    return findMatchCargo;
}

void Store::RemoveFromStore(Cargo* cargo) {
    storeCargo_.erase(FindMatchCargo(cargo));
}

std::string Store::ResponseMessage(const Response& responseMessage) {
    switch (responseMessage) {
    case Response::done:
        return "Done!";
    case Response::lackOfCargo:
        return "Lack of cargo!";
    case Response::lackOfMoney:
        return "Lack of money!";
    case Response::lackOfSpace:
        return "Lack of space!";
    default:
        return "Unknown error. Try again!";
    }
}

Cargo* Store::GetCargo(uint16_t index) const {
    if (index < storeCargo_.size()) {
        return storeCargo_[index].get();
    }

    return nullptr;
}

Response Store::Buy(Cargo* cargo, uint16_t amount, Player* player) {
}

/*
Response Store::Sell(Cargo*, uint16_t, Player*) {
}
*/