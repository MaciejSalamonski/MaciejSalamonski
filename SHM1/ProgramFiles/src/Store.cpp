#include "Store.hpp"

#include <algorithm>
#include <iomanip>
#include <random>

#include "Alcohol.hpp"
#include "Cargo.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Player.hpp"

Store::Store() {
    GenerateCargo();
}

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
    case Response::lackOfCargo:
        return "Lack of cargo!";
    case Response::lackOfMoney:
        return "Lack of money!";
    case Response::lackOfSpace:
        return "Lack of space!";
    case Response::done:
        return "Done!";
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

void Store::LoadCargoToStore(std::unique_ptr<Cargo> cargo, uint16_t amount) {
    auto IsCargoUnique = FindMatchCargo(cargo.get());

    if (IsCargoUnique == storeCargo_.end()) {
        storeCargo_.push_back(std::move(cargo));

        return;
    }

    **IsCargoUnique += amount;
}

void Store::UnloadCargoFromStore(std::unique_ptr<Cargo> cargo, uint16_t amount) {
    auto IsCargoUnique = FindMatchCargo(cargo.get());

    if (IsCargoUnique == storeCargo_.end()) {
        return;
    }

    if ((*IsCargoUnique)->GetAmount() <= cargo->GetAmount()) {
        RemoveFromStore(cargo.get());

        return;
    }

    **IsCargoUnique -= amount;
}

Response Store::Buy(Cargo* cargo, uint16_t amount, Player* player) {
    auto choosenCargo = FindMatchCargo(cargo);

    if (((*choosenCargo)->GetAmount() < amount) || (choosenCargo == storeCargo_.end())) {
        return Response::lackOfCargo;
    }

    if ((*choosenCargo)->GetPrice() * amount > player->GetMoney()) {
        return Response::lackOfMoney;
    }

    if (amount > player->GetAvailableSpace()) {
        return Response::lackOfSpace;
    }

    std::unique_ptr<Cargo> uniquePtrCargo(cargo);
    UnloadCargoFromStore(std::move(uniquePtrCargo), amount);
    player->SetMoney(player->GetMoney() - (*choosenCargo)->GetPrice() * amount);
    player->LoadCargoOnShip(std::move(uniquePtrCargo), amount);

    return Response::done;
}

Response Store::Sell(Cargo* cargo, uint16_t amount, Player* player) {
    std::unique_ptr<Cargo> uniquePtrCargo(cargo);
    LoadCargoToStore(std::move(uniquePtrCargo), amount);
    player->SetMoney(player->GetMoney() + cargo->GetPrice());
    player->UnloadCargoFromShip(std::move(uniquePtrCargo), amount);

    return Response::done;
}

void Store::NextDay() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (const auto& cargo : storeCargo_) {
        std::uniform_int_distribution<> options(SUBSTRACT, ADD);
        std::uniform_int_distribution<> randomAmountEachDay(MIN_RANDOM_AMOUNT_EACH_DAY, MAX_RANDOM_AMOUNT_EACH_DAY);

        if (options(gen) == ADD) {
            *cargo += randomAmountEachDay(gen);
        } else {
            *cargo -= randomAmountEachDay(gen);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    for (const auto& cargo : store.storeCargo_) {
        out << '\n';
        out << std::setfill('#') << std::setw(40) << '\n';
        out << "Item name: " << std::setw(20) << cargo->GetName() << std::setw(3) << " | ";
        out << "Price: " << std::setw(20) << cargo->GetPrice() << std::setw(3) << " | ";
        out << "Amount: " << std::setw(20) << cargo->GetAmount() << std::setw(3) << " | ";
    }

    return out;
}