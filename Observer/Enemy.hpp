#pragma once

#include <iostream>
#include "Observer.hpp"

class Enemy : public Observer
{
    private:
            std::string name{""};
    public:
            explicit Enemy(const std::string& name): name(name) {};
            const std::string& getName() const
            {
                return name;
            };
            void print(std::ostream& os) const override
            {
                os << name;
            }
            void onNotify(const std::string& str) override
            {
                std::cout << name << " " << str << std::endl;
            };
};