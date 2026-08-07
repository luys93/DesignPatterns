#include "MaintenanceState.hpp"
#include "PendingState.hpp"

void MaintenanceState::repair(CoffeeMachine& machine)
{
    std::cout << "Coffee machine repaired successfully" << std::endl;
    machine.setStatus(std::make_unique<PendingState>()); 
}

void MaintenanceState::undo(CoffeeMachine& machine)
{
    static_cast<void>(machine);
    throw std::runtime_error("Operation not allowed: machine is in maintenance state");
}

void MaintenanceState::insertMoney(CoffeeMachine& machine, float money)
{
    static_cast<void>(machine);
    static_cast<void>(money);
    throw std::runtime_error("Operation not allowed: machine is in maintenance state");
}

void MaintenanceState::selectDrink(CoffeeMachine& machine, const std::string& drinkName)
{
    static_cast<void>(machine);
    static_cast<void>(drinkName);
    throw std::runtime_error("Operation not allowed: machine is in maintenance state");
}

const std::string& MaintenanceState::getStatus() const 
{
    return state_;
}

std::string MaintenanceState::prepareDrink(CoffeeMachine& machine)
{
    static_cast<void>(machine);
    throw std::runtime_error("Operation not allowed: machine is in maintenance state");
}
