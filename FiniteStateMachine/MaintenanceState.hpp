#pragma once

#include "Astate.hpp"

class MaintenanceState : public AState
{
  
    public:
            MaintenanceState() = default;
            ~MaintenanceState() = default;
            MaintenanceState(const MaintenanceState& other) = delete;
            MaintenanceState(MaintenanceState&&) noexcept = default;
            MaintenanceState& operator=(const MaintenanceState& other) = delete;
            MaintenanceState& operator=(MaintenanceState&&) noexcept = default;
            void repair(CoffeeMachine& machine);

};