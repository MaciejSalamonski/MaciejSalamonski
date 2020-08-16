#pragma once

#include "Cargo.hpp"
#include "Player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : public Observer {
    std::vector<std::shared_ptr<Cargo>> cargos_;

    void generateCargo();
    void randomizeCargo(const std::vector<std::shared_ptr<Cargo>>&);
    std::vector<std::shared_ptr<Cargo>>::iterator findMatchCargo(std::shared_ptr<Cargo>);
    void removeFromStore(std::shared_ptr<Cargo>);

public:
    Store() = default;
    void load(std::shared_ptr<Cargo>);
    void unload(std::shared_ptr<Cargo>);
    std::string getResponseMessage(const Response&);
    Cargo* getCargo(const uint16_t) const;
    Response buy(Cargo*, uint16_t, Player*);
    Response sell(Cargo*, uint16_t, Player*);

    // Override from Observer
    void nextDay() override;
};