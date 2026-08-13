#include "Enemy.hpp"
#include "Magic.hpp"
#include "Melee.hpp"
#include "Bow.hpp"


int main()
{
   
    Enemy enemy(std::make_unique<Magic>());
    Enemy enemy2(std::make_unique<Melee>());
    Enemy enemy3(std::make_unique<Bow>());
    
    enemy.tryAttack();
    enemy2.tryAttack();
    enemy3.tryAttack();

}