#pragma once

#include <iostream>
#include "Observer.hpp"

class Enemy : public Observer
{
    private:
            std::string name{""};
    public:
            Enemy(const std::string& name): name(name) {};
            ~Enemy() = default;
            Enemy(const Enemy& other) = delete;
            Enemy& operator=(const Enemy& other) = delete;
            Enemy(Enemy&&) noexcept = default;
            Enemy& operator=(Enemy&&) noexcept = default;
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