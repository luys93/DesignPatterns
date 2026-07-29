#pragma once


class InterfaceEnemy 
{
    
    public:

        virtual ~InterfaceEnemy() = default;
        virtual void tryAttack() = 0;
};