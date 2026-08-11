#pragma once

#include "AttackDecorator.hpp"

class PoisonDecorator : public AttackDecorator
{
   
    public:
            explicit PoisonDecorator(std::unique_ptr<InterfaceAttack> attack) : AttackDecorator::AttackDecorator(std::move(attack)) {};
            void chooseAttack() override
            {
                AttackDecorator::chooseAttack();
                std::cout << " -> +5 poison damage\n";
            }; 
};