#pragma once

#include <stdint.h>

#include <vector>

#include "Observer.hpp"

class Time {
    uint16_t timeElapsed_;
    std::vector<Observer*> observers_;
    //ObserverIT getObserverIt(Observer*);
public:
    Time();
    void addObserver(Observer*);
    void removeObserver(Observer*);

    uint16_t getElapsedTime() const;
    Time& operator++();
};