#include "AudioManager.hpp"


void AudioManager::setString(const std::string& str)
{
    this->str = str;
}

std::ostream& operator<<(std::ostream& os, const AudioManager& a)
{
    std::cout << a.str << std::endl;
    return os;
}

AudioManager& AudioManager::getInstance()
{
   static AudioManager instance;
   return instance;
}