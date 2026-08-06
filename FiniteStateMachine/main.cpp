#include "MaintenanceState.hpp"
#include "PendingState.hpp"

int main()
{
   
    CoffeeMachine machine(std::make_unique<PendingState>());
    
    try
    {
   
        machine.buyDrinks("coffee", 1.5);
        std::cout << "{PRE}: " << machine << std::endl;
        machine.undo();
        std::cout << "{POST}: " << machine << std::endl;

        machine.setStatus(std::make_unique<MaintenanceState>());
        std::cout << "{STATUS}: " << machine << std::endl;
        machine.repair();
        std::cout << "{STATUS POST MAINTENANCE}: " << machine << std::endl;
        machine.buyDrinks("coffee", 1.5);
        std::cout << "{POST}: " << machine << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}