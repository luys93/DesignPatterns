#include "Enemy.hpp"



Enemy::Enemy()
{

}



void Enemy::setAttack(std::unique_ptr<InterfaceAttack> type)
{
    attack = std::move(type);
}


void Enemy::tryAttack()
{
    if(!attack)
        std::cout << "Any attack has been implemented" << std::endl;
    else
        attack->chooseAttack();
}