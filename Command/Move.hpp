#pragma once


class Move : public ICommand
{
    private:
            float deltaX{0};
            float deltaY{0};
            Receiver& receive;
    public:
            Move(float deltaX, float deltaY, Receiver& recive);
            void undo() override;
            void execute() override;
            float getDeltaX() const;
            float getDeltaY() const;
};