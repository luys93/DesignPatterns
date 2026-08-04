#include "AttackDecorator.hpp"


AttackDecorator::AttackDecorator(std::unique_ptr<InterfaceAttack> wrapper) : wrapperAttack{std::move(wrapper)}
{

}


void AttackDecorator::chooseAttack()
{
    if(wrapperAttack)
        wrapperAttack->chooseAttack();
}