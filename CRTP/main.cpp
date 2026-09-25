#include "CRTP.hpp"


int main()
{
    InkJet i;
    i.display("Printing, Wait...");

    Pen p;
    p.display("Writing, Wait...");

    TypeWriter w;
    w.display("Typing, Wait...");
}