#pragma once

#include "Map.hpp"
#include "Time.hpp"
#include "Player.hpp"

class Game {
    uint16_t money_;
    uint8_t days;
    uint16_t finalGoal_;
    uint8_t currentDay_;
    Map* map_;
    Time* time_;
    Player* player_;

public:
    Game();
    void StartGame();

};