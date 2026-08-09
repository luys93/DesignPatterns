#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "ICommand.hpp"

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
            void addCommand(std::unique_ptr<ICommand> command);
            void undoCommand();
            void executeCommand();

};