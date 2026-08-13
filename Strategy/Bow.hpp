#pragma once

#include "InterfaceAttack.hpp"

class Bow : public InterfaceAttack
{
    private:
        std::string str_{"Bow"};
    public:
        void chooseAttack() override
        {
            std::cout << "The enemy attack with " << str_ << std::endl;
        };
};