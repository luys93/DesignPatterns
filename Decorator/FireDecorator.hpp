#pragma once

#include "AttackDecorator.hpp"

class FireDecorator: public AttackDecorator
{
    public:
           explicit FireDecorator(std::unique_ptr<InterfaceAttack> attack): AttackDecorator::AttackDecorator(std::move(attack)) {};
            void chooseAttack() override
            {
                AttackDecorator::chooseAttack();
                std::cout << " -> +10 Fire Damage";
            }

};