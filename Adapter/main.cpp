#include "Enemy.hpp"
#include "Magic.hpp"
#include "Melee.hpp"
#include "Bow.hpp"
#include "Adapter.hpp"


int main()
{
   
    Enemy enemy;
    Enemy enemy2;
    Enemy enemy3;
    Enemy enemy4;

    enemy.setAttack(std::make_unique<Magic>());
    enemy2.setAttack(std::make_unique<Melee>());
    enemy3.setAttack(std::make_unique<Bow>());
    enemy4.setAttack(std::make_unique<Adapter>());
    
    enemy.tryAttack();
    enemy2.tryAttack();
    enemy3.tryAttack();
    enemy4.tryAttack();

}