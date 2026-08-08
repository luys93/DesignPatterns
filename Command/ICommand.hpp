#pragma once

class ICommand
{
    public:
            virtual ~ICommand() = default;
            virtual void undo() = 0;
            virtual void execute() = 0;
};