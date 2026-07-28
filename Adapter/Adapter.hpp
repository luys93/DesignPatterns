#pragma once

#include "InterfaceAttack.hpp"
#include "LegacyDragon.hpp"

class Adapter : public InterfaceAttack 
{
    private:
            std::unique_ptr<LegacyDragon> dragon{std::make_unique<LegacyDragon>()};
    public:
            Adapter() = default;
            ~Adapter() = default;
            Adapter(const Adapter& other) = delete;
            Adapter& operator=(const Adapter& other) = delete;
            Adapter(Adapter&&) noexcept = default;
            Adapter& operator=(Adapter&&) noexcept = default;
            void chooseAttack() override
            {
                dragon->breatheFire();
            };
};