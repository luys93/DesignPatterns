#include "Subject.hpp"
#include "Enemy.hpp"

int main()
{
    Subject sub;
    auto enemy = std::make_shared<Enemy>("Bad man");
 

    sub.addObserver(enemy);
    sub.printForTest();
    sub.notify("death");
    sub.removeObserver(enemy);
    sub.printForTest();

}