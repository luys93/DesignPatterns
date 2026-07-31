#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Observer.hpp"

class Subject
{
    private:
            std::vector<Observer*> observerVec;  
    public:
            Subject() = default;
            ~Subject() = default;
            Subject(const Subject& other) = delete;
            Subject& operator=(const Subject& other) = delete;
            Subject(Subject&&) noexcept = default;
            Subject& operator=(Subject&&) noexcept = default;
            void addObserver(Observer* ob);
            void removeObserver(Observer* ob);
            void notify(const std::string& str);
            void printForTest();
};