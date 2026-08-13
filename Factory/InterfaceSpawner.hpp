#pragma once

#include "InterfaceEnemy.hpp"
#include <memory>

class InterfaceSpawner
{
    public:
            InterfaceSpawner() = default;
            virtual ~InterfaceSpawner() = default;
            InterfaceSpawner(const InterfaceSpawner& other) = delete;
            InterfaceSpawner(InterfaceSpawner&&) noexcept = default;
            InterfaceSpawner& operator=(const InterfaceSpawner& other) = delete;
            InterfaceSpawner& operator=(InterfaceSpawner&&) noexcept = default;
            virtual std::unique_ptr<InterfaceEnemy> createEnemy() = 0;
};