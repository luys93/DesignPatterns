#pragma once

#include <memory>
#include "InterfaceAttack.hpp"


class Enemy 
{
    private:
            std::unique_ptr<InterfaceAttack> attack = nullptr;
    public:
        Enemy();
        void setAttack(std::unique_ptr<InterfaceAttack> type);
        void tryAttack() ;
};