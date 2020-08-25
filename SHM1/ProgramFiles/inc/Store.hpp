#pragma once

#include "Cargo.hpp"
#include "Player.hpp"

namespace {
    constexpr uint8_t NUMBER_OF_ITEMS = 15;
    constexpr uint8_t MIN_RANDOM_AMOUNT = 0;
    constexpr uint8_t MAX_RANDOM_AMOUNT = 10;
}  

enum class Response {
    lackOfMoney,
    lackOfCargo,
    lackOfSpace,
    done
};

class Store : public Observer {
    std::vector<std::unique_ptr<Cargo>> storeCargo_;

    void GenerateCargo();
    void RandomizeCargo(std::vector<std::unique_ptr<Cargo>>&);
    std::vector<std::unique_ptr<Cargo>>::iterator FindMatchCargo(Cargo*);
    void RemoveFromStore(Cargo*);
    std::string ResponseMessage(const Response&);

public:
    Store();
    Cargo* GetCargo(uint16_t) const;
    Response Buy(Cargo*, uint16_t, Player*);
    Response Sell(Cargo*, uint16_t, Player*);

    //Override from Observer
    void NextDay() override;
    ~Store() override;
};