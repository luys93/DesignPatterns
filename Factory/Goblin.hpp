#pragma once

#include <iostream>
#include "InterfaceEnemy.hpp"

class Goblin : public InterfaceEnemy
{
    private:
            std::string type{""};
            std::string weapon{""};
    public:
            Goblin(const std::string& type, const std::string& weapon): type(type), weapon(weapon) {};
            void tryAttack() override {std::cout << type << " attack with " << weapon << std::endl;};

};