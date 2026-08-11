#pragma once

#include <iostream>
#include <memory>
#include "InterfaceAttack.hpp"

class AttackDecorator: public InterfaceAttack
{
    private:
            std::unique_ptr<InterfaceAttack> wrapperAttack;

    public:
            explicit AttackDecorator(std::unique_ptr<InterfaceAttack> wrapper);
            void chooseAttack() override;
};