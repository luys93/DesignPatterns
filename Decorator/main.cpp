#include "Enemy.hpp"
#include "Magic.hpp"
#include "Melee.hpp"
#include "Bow.hpp"
#include "FireDecorator.hpp" 
#include "PoisonDecorator.hpp"


int main()
{
   
    Enemy enemy;
    Enemy enemy2;
    Enemy enemy3;



    std::unique_ptr<InterfaceAttack> bowAttack = std::make_unique<PoisonDecorator>(std::make_unique<FireDecorator>(std::make_unique<Bow>()));
    enemy.setAttack(std::move(bowAttack));
    enemy.tryAttack();

    std::unique_ptr<InterfaceAttack> magicAttack = std::make_unique<PoisonDecorator>(std::make_unique<FireDecorator>(std::make_unique<Magic>()));
    enemy2.setAttack(std::move(magicAttack));
    enemy2.tryAttack();


    std::unique_ptr<InterfaceAttack> meleeAttack = std::make_unique<PoisonDecorator>(std::make_unique<FireDecorator>(std::make_unique<Melee>()));
    enemy3.setAttack(std::move(meleeAttack));
    enemy3.tryAttack();
}