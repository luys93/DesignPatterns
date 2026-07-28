#include "Enemy.hpp"
#include "Magic.hpp"
#include "Melee.hpp"
#include "Bow.hpp"


int main()
{
   
    Enemy enemy;
    Enemy enemy2;
    Enemy enemy3;

    enemy.setAttack(std::make_unique<Magic>());
    enemy2.setAttack(std::make_unique<Melee>());
    enemy3.setAttack(std::make_unique<Bow>());
    
    enemy.tryAttack();
    enemy2.tryAttack();
    enemy3.tryAttack();

}