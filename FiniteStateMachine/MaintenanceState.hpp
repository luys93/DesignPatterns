#pragma once

#include "IState.hpp"
#include "CoffeeMachine.hpp"

class PendingState;

class MaintenanceState : public IState
{
    private:
            std::string state_{"Maintenance"};
  
    public:
            MaintenanceState() = default;
            ~MaintenanceState() = default;
            MaintenanceState(const MaintenanceState& other) = delete;
            MaintenanceState(MaintenanceState&&) noexcept = default;
            MaintenanceState& operator=(const MaintenanceState& other) = delete;
            MaintenanceState& operator=(MaintenanceState&&) noexcept = default;
            void repair(CoffeeMachine& machine) override;
            void undo(CoffeeMachine& machine) override;
            void insertMoney(CoffeeMachine& machine, float money) override;
            void selectDrink(CoffeeMachine& machine, const std::string& drinkName) override;
            const std::string& getStatus() const override;
};