#pragma once

#include <memory>
#include "IState.hpp"
#include "CoffeeMachine.hpp"

class EmanationState;

class PendingState: public IState
{
    private:
            std::string state_{"Pending"};
    public:
            void repair(CoffeeMachine& machine) override;
            void undo(CoffeeMachine& machine) override;
            void insertMoney(CoffeeMachine& machine, float money) override;
            void selectDrink(CoffeeMachine& machine, const std::string& drinkName) override;
            const std::string& getStatus() const override;
            std::string prepareDrink(CoffeeMachine& machine) override;
};