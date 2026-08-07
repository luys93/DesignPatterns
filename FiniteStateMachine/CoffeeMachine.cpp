#include "CoffeeMachine.hpp"

CoffeeMachine::CoffeeMachine(std::unique_ptr<IState> status): status_{std::move(status)}
{

}

void CoffeeMachine::setCurrentBalance(float money)
{
    currentBalance_ = money;
}

void CoffeeMachine::setSelectDrink(std::string drinkName)
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

const std::map<std::string, float>& CoffeeMachine::getAvailableDrinks() const
{
    return availableDrinks_;
}

std::ostream& operator<<(std::ostream& os, const CoffeeMachine& c)
{
    os << c.getSelectedDrink() << " - " << c.getCurrentBalance() << " - " << c.getStatus();
    return os;
}

void CoffeeMachine::prepareDrink()
{

    status_->prepareDrink(*this);
    std::cout << "Dispensing " << selectedDrink_ << " ..." <<std::endl;
}

void CoffeeMachine::buyDrinks(const std::string& drinkName, float money)
{
    status_ ->insertMoney(*this, money);
    status_ ->selectDrink(*this, drinkName);
}

void CoffeeMachine::undo()
{
    status_->undo(*this);
}

void CoffeeMachine::repair()
{
    status_->repair(*this);
}