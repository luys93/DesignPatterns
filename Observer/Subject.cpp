#include "Subject.hpp"


void Subject::addObserver(std::weak_ptr<Observer> ob)
{
    observerVec.push_back(ob);
}

void Subject::removeObserver(std::weak_ptr<Observer> ob)
{
   
   auto observer = ob.lock();
   if(!observer)
        return; 
   for(auto it = observerVec.begin(); it != observerVec.end(); ++it)
   {
        if(it->lock() == observer)
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
        if(auto observer = ob.lock())
            observer->onNotify(str);
    }   
        
}



void Subject::printForTest()
{
    for(auto& ob : observerVec)
    {
        if(auto observer = ob.lock())
            std::cout << *observer << std::endl;
        
    }
}