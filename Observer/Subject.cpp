#include "Subject.hpp"


void Subject::addObserver(Observer* ob)
{
    observerVec.push_back(ob);
}

void Subject::removeObserver(Observer* ob)
{
   

   for(auto it = observerVec.begin(); it != observerVec.end(); ++it)
   {

        if(*it == ob)
        {
            observerVec.erase(it);
            return;
        }
   }
}


void Subject::notify(const std::string& str)
{
    for(auto& ob : observerVec)
    {
        ob->onNotify(str);
    }   
        
}



void Subject::printForTest()
{
    for(auto& ob : observerVec)
    {
        std::cout << *ob << std::endl;
    }
}