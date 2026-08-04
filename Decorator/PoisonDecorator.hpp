#pragma once

#include "AttackDecorator.hpp"

class PoisonDecorator : public AttackDecorator
{
   
    public:
            PoisonDecorator() = delete;
            PoisonDecorator(std::unique_ptr<InterfaceAttack> attack) : AttackDecorator::AttackDecorator(std::move(attack)) {};
            ~PoisonDecorator() = default;
            PoisonDecorator(const PoisonDecorator& other) = delete;
            PoisonDecorator(PoisonDecorator&&) noexcept = default;
            PoisonDecorator& operator=(const PoisonDecorator& other) = delete;
            PoisonDecorator& operator=(PoisonDecorator&&) noexcept = default;
            void chooseAttack() override
            {
                AttackDecorator::chooseAttack();
                std::cout << " -> +5 poison damage\n";
            }; 
};