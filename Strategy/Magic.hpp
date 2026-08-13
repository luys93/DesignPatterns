#pragma once

#include "InterfaceAttack.hpp"


class Magic : public InterfaceAttack
{
    private:
            std::string str_{"fireball"};
    public:
            void chooseAttack() override
            {
                std::cout << "The Enemy attack with " << str_ << " Magic" << std::endl;
            }
};