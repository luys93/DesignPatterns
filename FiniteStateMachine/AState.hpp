#pragma once

#include <iostream>
#include <exception>

class CoffeeMachine;

class AState
{

    public:
            virtual ~AState() = 0;
            virtual void insertMoney(CoffeeMachine& machine, float money);
            virtual void selectDrink(CoffeeMachine& machine, const std::string& drinkName);
            virtual void undo(CoffeeMachine& machine);
            virtual void repair(CoffeeMachine& machine);
};

inline AState::~AState() = default;