#pragma once

#include "InterfaceSpawner.hpp"
#include "Wolf.hpp"


class WolfSpawner : public InterfaceSpawner
{
    private:
            std::string type{""};
    public:
            WolfSpawner(const std::string& type) : type(type) {};
            ~WolfSpawner() = default;
            std::unique_ptr<InterfaceEnemy> createEnemy() {return std::make_unique<Wolf>(type);};
};