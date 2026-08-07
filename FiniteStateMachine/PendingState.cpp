#include "PendingState.hpp"
#include "EmanationState.hpp"


void PendingState::repair(CoffeeMachine& machine)
{
    static_cast<void>(machine);
    throw std::runtime_error("Impossible action in this state");
}

void PendingState::undo(CoffeeMachine& machine)
{
    machine.setCurrentBalance(0);
    machine.setSelectDrink("none");
}

void PendingState::insertMoney(CoffeeMachine& machine, float money)
{
    machine.setCurrentBalance(machine.getCurrentBalance() + money);
}

void PendingState::selectDrink(CoffeeMachine& machine, const std::string& drinkName)
{
    machine.setSelectDrink(drinkName);
    machine.setStatus(std::make_unique<EmanationState>());
}

const std::string& PendingState::getStatus() const
{
    return state_;
}

std::string PendingState::prepareDrink(CoffeeMachine& machine)
{
    static_cast<void>(machine);
    throw std::runtime_error("Operation not allowed: machine is in Pending state");
}