#pragma once

#include "InterfaceAttack.hpp"

class Melee : public InterfaceAttack
{
    private:
            std::string str_{"Sword"};
    public:
            void chooseAttack() override
            {
                std::cout << "The Enemy attack with " << str_ << std::endl;
            }
};