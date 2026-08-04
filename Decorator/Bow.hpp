#pragma once

#include "InterfaceAttack.hpp"

class Bow : public InterfaceAttack
{
    private:
        std::string str{"Bow"};
    public:
        Bow() = default;
        virtual ~Bow() = default;
        void chooseAttack() override
        {
            std::cout << "The enemy attack with " << str;
        };
};