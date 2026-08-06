#include "CoffeeMachine.hpp"

CoffeeMachine::CoffeeMachine(std::unique_ptr<IState> status): status_{std::move(status)}
{

}

void CoffeeMachine::setCurrentBalance(float money)
{
    currentBalance_ = money;
}

void CoffeeMachine::setSelectDrink(const std::string& drinkName)
{
    selectedDrink_ = std::move(drinkName);
}

void CoffeeMachine::setStatus(std::unique_ptr<IState> status)
{
    status_ = std::move(status);
}

const std::string& CoffeeMachine::getSelectedDrink() const
{
    return selectedDrink_;
}

float CoffeeMachine::getCurrentBalance() const
{
    return currentBalance_;
};

const std::string& CoffeeMachine::getStatus() const
{
    return status_->getStatus();
}

std::ostream& operator<<(std::ostream& os, const CoffeeMachine& c)
{
    os << c.getSelectedDrink() << " - " << c.getCurrentBalance() << " - " << c.getStatus();
    return os;
}

std::string CoffeeMachine::prepareDrink()
{
    for(auto& drink : availableDrinks_)
    {
        if(drink.first == selectedDrink_ && currentBalance_ >= drink.second)
            return selectedDrink_;
        else if(drink.first == selectedDrink_ && currentBalance_ < drink.second)
            throw std::runtime_error("Insufficient balance for this drink");
    }
    throw std::runtime_error("Do not found this drink");
    return("");
}

void CoffeeMachine::buyDrinks(const std::string& drinkName, float money)
{
    status_ ->insertMoney(*this, money);
    status_ ->selectDrink(*this, drinkName);
    this->prepareDrink();
}

void CoffeeMachine::undo()
{
    status_->undo(*this);
}

void CoffeeMachine::repair()
{
    status_->repair(*this);
}