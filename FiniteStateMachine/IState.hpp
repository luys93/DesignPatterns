#pragma once

#include <iostream>

class CoffeeMachine;

class IState
{

    public:

            virtual ~IState() = default;
            IState() = default;
            IState(const IState& other) = delete;
            IState(IState&&) noexcept = default;
            IState& operator=(const IState& other) = delete;
            IState& operator=(IState&&) = default;
            virtual void insertMoney(CoffeeMachine& machine, float money) = 0;
            virtual void selectDrink(CoffeeMachine& machine, const std::string& drinkName) = 0;
            virtual void undo(CoffeeMachine& machine) = 0;
            virtual void repair(CoffeeMachine& machine) = 0;
            virtual std::string prepareDrink(CoffeeMachine& machine) = 0;
            virtual const std::string& getStatus() const = 0;
};