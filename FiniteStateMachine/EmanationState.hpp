#pragma once

#include "IState.hpp"

class CoffeeMachine;
class PendingState;

class EmanationState : public IState
{
    private:
            std::string status{"Emanation"};
    
    public:
            void repair(CoffeeMachine& machine) override;
            void undo(CoffeeMachine& machine) override;
            void insertMoney(CoffeeMachine& machine, float money) override;
            void selectDrink(CoffeeMachine& machine, const std::string& drinkName) override;
            const std::string& getStatus() const override;
            std::string prepareDrink(CoffeeMachine& machine) override;
};