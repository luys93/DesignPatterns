#pragma once

#include <iostream>
#include <vector>

class Invoker
{
    private:
            std::vector<std::unique_ptr<ICommand> > VCommand;
    public:
            Invoker() = default;
            ~Invoker() = default;
            Invoker(const Invoker& other) = delete;
            Invoker(Invoker&&) noexcept = default;
            Invoker& operator=(const Invoker& other) = delete;
            Invoker& operator=(Invoker&&) noexcept = default;

};