#include "PendingState.hpp"


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
    machine.setStatus(std::make_unique<PendingState>());
    machine.setCurrentBalance(money);
}

void PendingState::selectDrink(CoffeeMachine& machine, const std::string& drinkName)
{
    machine.setSelectDrink(drinkName);
}

const std::string& PendingState::getStatus() const
{
    return state_;
}