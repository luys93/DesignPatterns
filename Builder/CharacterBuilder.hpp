#pragma once

#include <iostream>
#include <memory>
#include "Character.hpp"


class CharacterBuilder 
{
    private:
            std::string name_{""};
            std::string weapon_{""};
            int hp_{0};
            int damage_{0};
            int criticalDamage_{0};
    public:
            CharacterBuilder() = default;
            ~CharacterBuilder() = default;
            CharacterBuilder& setName(const std::string& name) {name_ = name; return *this;};
            CharacterBuilder& setWeapon(const std::string& weapon) {weapon_ = weapon; return *this;};
            CharacterBuilder& setHp(int hp) {hp_ = hp; return *this;};
            CharacterBuilder& setDamage(int damage) {damage_ = damage; return *this;};
            CharacterBuilder& setCriticalDamage(int criticalDamage) {criticalDamage_  = criticalDamage; return *this;};
            Character build() const
            {
                return Character(name_ , weapon_ , hp_ , damage_ , criticalDamage_ );
            };
};