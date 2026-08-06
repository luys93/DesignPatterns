#pragma once

#include <memory>
#include "IState.hpp"
#include "CoffeeMachine.hpp"

class PendingState: public IState
{
    private:
            std::string state_{"Pending"};
    public:
            PendingState() = default;
            ~PendingState() = default;
            PendingState(const PendingState& other) = delete;
            PendingState(PendingState&&) noexcept = default;
            PendingState& operator=(const PendingState& other) = delete;
            PendingState& operator=(PendingState&&) noexcept = default;
            void repair(CoffeeMachine& machine) override;
            void undo(CoffeeMachine& machine) override;
            void insertMoney(CoffeeMachine& machine, float money) override;
            void selectDrink(CoffeeMachine& machine, const std::string& drinkName) override;
            const std::string& getStatus() const override;
};