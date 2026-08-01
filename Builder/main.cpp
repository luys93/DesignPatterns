#include "CharacterBuilder.hpp"


int main()
{
    CharacterBuilder builder;
    auto character = builder.setName("LeChuck")
                     .setWeapon("Sword")
                     .setHp(100)
                     .setDamage(30)
                     .setCriticalDamage(50)
                     .build();

    std::cout << character.print() << std::endl;
}