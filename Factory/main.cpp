#include "GoblinSpawner.hpp"
#include "WolfSpawner.hpp"
#include <iostream>

int main()
{
    GoblinSpawner factoryGoblin("King Goblin", "Axe");
    WolfSpawner factoryWolf("Black Wolf");
    auto Goblin = factoryGoblin.createEnemy();
    auto Wolf = factoryWolf.createEnemy();

    Goblin->tryAttack();
    Wolf->tryAttack();
}