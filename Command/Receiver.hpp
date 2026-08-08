#pragma once

#include <iostream>


class Receiver
{   
    private:
            float x{0.f};
            float y{0.f};
    public:
            Receiver() = default;
            ~Receiver() = default;
            Receiver(const Receiver& other) = delete;
            Receiver(Receiver&&) noexcept = default;
            Receiver& operator=(const Receiver& other) = delete;
            Receiver& operator=(Receiver&&) noexcept = default;
            void setCoordinates(float x, float y);


};