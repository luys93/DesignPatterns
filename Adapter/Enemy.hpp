#pragma once

#include <memory>
#include "InterfaceAttack.hpp"


class Enemy 
{
    private:
            std::unique_ptr<InterfaceAttack> attack = nullptr;
    public:
        Enemy();
        ~Enemy() = default;
        Enemy(Enemy&&) noexcept = default;
        Enemy& operator=(Enemy&&) noexcept = default;
        void setAttack(std::unique_ptr<InterfaceAttack> type);
        void tryAttack() ;
};