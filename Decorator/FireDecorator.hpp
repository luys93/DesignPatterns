#pragma once

#include "AttackDecorator.hpp"

class FireDecorator: public AttackDecorator
{
    public:
            FireDecorator(std::unique_ptr<InterfaceAttack> attack): AttackDecorator::AttackDecorator(std::move(attack)) {};
            ~FireDecorator() = default;
            FireDecorator(const FireDecorator& other) = delete;
            FireDecorator(FireDecorator&&) noexcept = default;
            FireDecorator& operator=(const FireDecorator& other) = delete;
            FireDecorator& operator=(FireDecorator&&) = default;
            void chooseAttack() override
            {
                AttackDecorator::chooseAttack();
                std::cout << " -> +10 Fire Damage";
            }

};