#include "Subject.hpp"
#include "Enemy.hpp"

int main()
{
    Subject sub;
    Enemy enemy("Bad man");
   

 

    sub.addObserver(&enemy);
    sub.printForTest();
    sub.notify("death");
    sub.removeObserver(&enemy);
    sub.printForTest();

}