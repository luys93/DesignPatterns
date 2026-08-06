#pragma once

#include <iostream>

class CoffeeMachine;

class IState
{

    public:
            virtual ~IState() = default;
            virtual void insertMoney(CoffeeMachine& machine, float money) = 0;
            virtual void selectDrink(CoffeeMachine& machine, const std::string& drinkName) = 0;
            virtual void undo(CoffeeMachine& machine) = 0;
            virtual void repair(CoffeeMachine& machine) = 0;
            virtual const std::string& getStatus() const = 0;
};