#include "Invoker.hpp"



void Invoker::addCommand(std::unique_ptr<ICommand> command)
{
    VCommand.push_back(std::move(command));
}


void Invoker::undoCommand()
{
    if(VCommand.empty())
        return;
    VCommand.back()->undo();
    VCommand.pop_back();
}

void Invoker::executeCommand()
{
    for(const auto& cmd: VCommand)
    {
        cmd->execute();
    }
}