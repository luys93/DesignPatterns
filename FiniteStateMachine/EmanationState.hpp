#pragma once

#include "IState.hpp"

class CoffeeMachine;
class PendingState;

class EmanationState : public IState
{
    private:
            std::string status{"Emanation"};
    
    public:
            EmanationState() = default;
            ~EmanationState() = default;
            EmanationState(const EmanationState& other) = delete;
            EmanationState(EmanationState&&) noexcept = default;
            EmanationState& operator=(const EmanationState& other) = delete;
            EmanationState& operator=(EmanationState&&) noexcept = default;
            void repair(CoffeeMachine& machine) override;
            void undo(CoffeeMachine& machine) override;
            void insertMoney(CoffeeMachine& machine, float money) override;
            void selectDrink(CoffeeMachine& machine, const std::string& drinkName) override;
            const std::string& getStatus() const override;
            std::string prepareDrink(CoffeeMachine& machine) override;
};