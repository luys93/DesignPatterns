#pragma once

#include <iostream>


template<typename Derived>
class Text
{
    public:
        void display(const std::string& str) const
        {
            std::string result = static_cast<const Derived*>(this)->getText(str);
            std::cout << "*** " << result << " ***" << std::endl; 
        }
};



class InkJet : public Text<InkJet>
{
    public:
        std::string getText(const std::string& str) const
        {
            return "[InkJet] " + str;
        }
};



class Pen : public Text<Pen>
{
    public:
        std::string getText(const std::string& str) const
        {
            
            return "[PEN] " + str;
        }
};


class TypeWriter : public Text<TypeWriter>
{
    public:
        std::string getText(const std::string& str) const
        {
            return "[TypeWriter] " + str;
        }
};