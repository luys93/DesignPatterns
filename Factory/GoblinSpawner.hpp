#pragma once

#include "InterfaceSpawner.hpp"
#include "Goblin.hpp"

class GoblinSpawner : public InterfaceSpawner
{
    private:
            std::string type{""};
            std::string weapon{""};
    public:
            GoblinSpawner(const std::string& type, const std::string& weapon) : type(type), weapon(weapon) {};
            std::unique_ptr<InterfaceEnemy> createEnemy() { return std::make_unique<Goblin>(type, weapon);};
    
};