#pragma once

#include <stdint.h>

#include <vector>

#include "Observer.hpp"

class Time {
    uint16_t timeElapsed_;
    std::vector<Observer*> obserwers_;

public:
    Time();
    void AddObserver(Observer*);
    void RemoveObserver(Observer*);
    uint16_t GetElapsedTime() const { return timeElapsed_; }
    Time& operator++();
};
