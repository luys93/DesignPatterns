#pragma once

class Observer
{
    public:
        Observer() = default;
        Observer(const Observer& other) = delete;
        Observer(Observer&&) noexcept = default;
        Observer& operator=(const Observer& other) = delete;
        Observer& operator=(Observer&&) noexcept = default;
        virtual ~Observer() = default; 
        virtual void onNotify(const std::string& str) = 0;
        virtual void print(std::ostream& os) const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Observer& ob)
        {
            ob.print(os);
            return os;
        };
};