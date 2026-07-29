#pragma once

#include <iostream>
#include "InterfaceEnemy.hpp"

class Wolf : public InterfaceEnemy
{
    private:
            std::string type{""};

    public:
            Wolf(const std::string& type) : type(type) {};
            ~Wolf() = default;
            void tryAttack() override {std::cout << type << " bite attack" << std::endl;}
};