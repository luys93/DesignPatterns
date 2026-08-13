#pragma once


class InterfaceEnemy 
{
    
    public:
        InterfaceEnemy() = default;
        virtual ~InterfaceEnemy() = default;
        InterfaceEnemy(const InterfaceEnemy& other) = delete;
        InterfaceEnemy(InterfaceEnemy&&) noexcept = default;
        InterfaceEnemy& operator=(const InterfaceEnemy& other) = delete;
        InterfaceEnemy& operator=(InterfaceEnemy&&) noexcept = default;
        virtual void tryAttack() = 0;
};