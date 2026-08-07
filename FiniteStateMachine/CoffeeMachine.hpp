#pragma once

#include <iostream>
#include <memory>
#include <map>
#include "IState.hpp"

class CoffeeMachine
{
    private:
            float currentBalance_{0};
            std::string selectedDrink_{""};
            std::map<std::string, float> availableDrinks_{{"coffee", 1.5f}, {"tea", 1.0f}, {"coca cola", 2.0f}};
            std::unique_ptr<IState> status_;
    public:
            CoffeeMachine(std::unique_ptr<IState> status);
            ~CoffeeMachine() = default;
            CoffeeMachine(const CoffeeMachine& other) = delete;
            CoffeeMachine(CoffeeMachine&&) noexcept = default;
            CoffeeMachine& operator=(const CoffeeMachine& other) = delete;
            CoffeeMachine& operator=(CoffeeMachine&&) noexcept = default;
            void setCurrentBalance(float money);
            void setSelectDrink(std::string drinkName);
            void setStatus(std::unique_ptr<IState> status);
            const std::string& getSelectedDrink() const;
            float getCurrentBalance() const;
            const std::map<std::string, float>& getAvailableDrinks() const;
            const std::string& getStatus() const;
            friend std::ostream& operator<<(std::ostream& os, const CoffeeMachine& c);
            void prepareDrink();
            void buyDrinks(const std::string& drinkName, float money);
            void undo();
            void repair();
};