#pragma once

#include <sstream>

class Character
{
    private:
            std::string name_{""};
            std::string weapon_{""};
            int hp_{0};
            int damage_{0};
            int criticalDamage_{0};
            Character(const std::string& name, const std::string& weapon, int hp, int damage, int criticalDamage)
            :name_{name}, weapon_{weapon}, hp_{hp}, damage_{damage}, criticalDamage_{criticalDamage}{};
    public:
            Character() = delete;
            ~Character() = default;
            Character(const Character& other) = delete;
            Character& operator=(const Character& other) = delete;
            Character(Character&&) noexcept = default;
            Character& operator=(Character&&) noexcept = default; 
            friend class CharacterBuilder;
            std::string print()
            {
                std::stringstream ss;
                ss << "name: " << name_ << "\n"
                   << "weapon: " << weapon_ << "\n"
                   << "hp: " << hp_ << "\n"
                   << "damage: " << damage_ << "\n"
                   << "criticalDamage: " << criticalDamage_;
                return ss.str();
            }
};