#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Observer.hpp"

class Subject
{
    private:
            //std::vector<Observer*> observerVec;
            std::vector<std::weak_ptr<Observer> > observerVec;  
    public:
            Subject() = default;
            void addObserver(std::weak_ptr<Observer> ob);
            void removeObserver(std::weak_ptr<Observer> ob);
            void notify(const std::string& str);
            void printForTest();
};