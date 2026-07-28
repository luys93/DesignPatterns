#pragma once

#include "InterfaceAttack.hpp"

class Melee : public InterfaceAttack
{
    private:
            std::string str{"Sword"};
    public:
            Melee() = default;
            ~Melee() = default;
            void chooseAttack() override
            {
                std::cout << "The Enemy attack with " << str << std::endl;
            }
};