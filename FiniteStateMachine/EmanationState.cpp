#include "EmanationState.hpp"
#include "CoffeeMachine.hpp"
#include "PendingState.hpp"

void EmanationState::repair(CoffeeMachine& machine)
{
    static_cast<void>(machine);
    throw std::runtime_error("Operation not allowed: machine is in Emanation state");
}

void EmanationState::undo(CoffeeMachine& machine)
{
    static_cast<void>(machine);
    throw std::runtime_error("Operation not allowed: machine is in Emanation state");
}

void EmanationState::insertMoney(CoffeeMachine& machine, float money)
{
    static_cast<void>(machine);
    static_cast<void>(money);
    throw std::runtime_error("Operation not allowed: machine is in Emanation state");
}

void EmanationState::selectDrink(CoffeeMachine& machine, const std::string& drinkName)
{
    static_cast<void>(machine);
    static_cast<void>(drinkName);
    throw std::runtime_error("Operation not allowed: machine is in Emanation state");
}

const std::string& EmanationState::getStatus() const
{
    return status;
}

std::string EmanationState::prepareDrink(CoffeeMachine& machine)
{
    auto availableDrinks = machine.getAvailableDrinks();
    auto currentBalance = machine.getCurrentBalance();
    auto selectDrink = machine.getSelectedDrink(); 

    for(const auto& drink: availableDrinks)
    {
        if(drink.first == selectDrink && currentBalance >= drink.second)
        {
            machine.setCurrentBalance(currentBalance - drink.second);
            machine.setStatus(std::make_unique<PendingState>());
            return drink.first;
        }
        if(drink.first == selectDrink && currentBalance < drink.second)
            throw std::runtime_error("Insufficient balance for this drink");
    }
    throw std::runtime_error("Do not found this drink");
}