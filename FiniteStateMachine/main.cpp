#include "MaintenanceState.hpp"
#include "PendingState.hpp"
#include <sstream>
#include <thread>
#include <chrono>


int main()
{

    std::string input;
    std::string money;
    CoffeeMachine machine(std::make_unique<PendingState>()); 

    
    while(1)
    {
        try
        {
            std::cout << "The machine is ready{INPUT: Buy / Error / Exit}: ";
            if(!std::getline(std::cin, input) || input == "Exit")
                    break;
            if(input == "Error")
            {
                machine.setStatus(std::make_unique<MaintenanceState>());
                std::cout << "Repair?{Yes / No}: " ;
                std::getline(std::cin, input);
                if(input == "undo")
                    machine.undo();
                else if(input == "Yes")
                    machine.repair();
                else
                    continue;
            }
            else if(input == "Buy")
            {
                std::string name;
                std::cout << "choose drink{coffee - 1.5; tea - 1; coca cola 2}: ";
                std::getline(std::cin, name);
                std::cout << "insert money: ";
                std::getline(std::cin, money);
                if(name == "undo" || money == "undo")
                    machine.undo();
                else
                {
                    std::stringstream ss(money);
                    float balance = 0.0f;
                    ss >> balance;
                    machine.buyDrinks(name, balance);
                    std::cout << "currentBalance: " << machine.getCurrentBalance() << std::endl;
                    machine.prepareDrink();
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                    std::cout << machine.getSelectedDrink() << " is ready" << std::endl;
                    std::cout << "currentBalance: " << machine.getCurrentBalance() << std::endl;
                }
            }
            else
                std::cout << "Invalid command: Only input valid is: <Buy>, <Error> or <Exit>" << std::endl;

        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}