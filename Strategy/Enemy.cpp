#include "Enemy.hpp"


Enemy::Enemy(std::unique_ptr<InterfaceAttack> type) : attack_{std::move(type)}
{

}


void Enemy::tryAttack()
{
    if(!attack_)
        std::cout << "Any attack has been implemented" << std::endl;
    else
        attack_->chooseAttack();
}