#pragma once

class Observer
{
    public:
        virtual ~Observer() = default; 
        virtual void onNotify(const std::string& str) = 0;
        virtual void print(std::ostream& os) const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Observer& ob)
        {
            ob.print(os);
            return os;
        };
};