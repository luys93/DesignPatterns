#pragma once

#include <iostream>
#include <memory>
#include "InterfaceAttack.hpp"

class AttackDecorator: public InterfaceAttack
{
    private:
            std::unique_ptr<InterfaceAttack> wrapperAttack;

    public:
            AttackDecorator(std::unique_ptr<InterfaceAttack> wrapper);
            AttackDecorator() = delete;
            ~AttackDecorator() = default;
            AttackDecorator(const AttackDecorator& other) = delete;
            AttackDecorator(AttackDecorator&&) = default;
            AttackDecorator& operator=(const AttackDecorator& other) = delete;
            AttackDecorator& operator=(AttackDecorator&&) = default;
            void chooseAttack() override;
};