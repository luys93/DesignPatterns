#include "AudioManager.hpp"

int main()
{
    std::cout << "instance: "<< AudioManager::getInstance() << std::endl;
    AudioManager::getInstance().setString("Hello");
    std::cout << "Then instance: " << AudioManager::getInstance() << std::endl;
}