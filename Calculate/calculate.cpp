#include "calculate.hpp"

#include <iostream>
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    if (command == "add") {
        return std::to_string(first + second);
    }
    if (command == "subtract") {
        return std::to_string(first - second);
    }
    if (command == "multiply") {
        return std::to_string(first * second);
    }
    if (command == "divide") {
        return (second > 0) ? std::to_string(first / second) : "You can't divide by zero! Try again.";
    }
    return "Invalid data! Try again.";
}