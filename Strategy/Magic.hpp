#pragma once

#include "InterfaceAttack.hpp"


class Magic : public InterfaceAttack
{
    private:
            std::string str{"fireball"};
    public:
            Magic() = default;
            ~Magic() = default;
            void chooseAttack() override
            {
                std::cout << "The Enemy attack with " << str << " Magic" << std::endl;
            }
};