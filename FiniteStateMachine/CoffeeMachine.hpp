#pragma once

#include <iostream>
#include <memory>
#include <map>
#include "AState.hpp"

class CoffeeMachine
{
    private:
            float currentBalance_{0};
            std::map<std::string, float> availableDrinks_;
            std::unique_ptr<AState> status_;
    public:
            CoffeeMachine() = default;
            ~CoffeeMachine() = default;
            CoffeeMachine(const CoffeeMachine& other) = delete;
            CoffeeMachine(CoffeeMachine&&) noexcept = default;
            CoffeeMachine& operator=(const CoffeeMachine& other) = delete;
            CoffeeMachine& operator=(CoffeeMachine&&) noexcept = default;

};