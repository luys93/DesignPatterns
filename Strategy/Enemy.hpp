#pragma once

#include <memory>
#include "InterfaceAttack.hpp"


class Enemy 
{
    private:
            std::unique_ptr<InterfaceAttack> attack_;
    public:
        explicit Enemy(std::unique_ptr<InterfaceAttack> attack);    
        void tryAttack();
};