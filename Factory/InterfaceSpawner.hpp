#pragma once

#include "InterfaceEnemy.hpp"
#include <memory>

class InterfaceSpawner
{
    public:
            virtual ~InterfaceSpawner() = default;
            virtual std::unique_ptr<InterfaceEnemy> createEnemy() = 0;
};