#include <iostream>
#include <vector>
#include "Unit.h"

int main(int argc, char *argv[])
{
    std::string fName1 = argv[1];
    std::string fName2 = argv[2];
    Unit *u1;
    Unit *u2;

    try
    {
        u1 = new Unit(Unit::ParseUnit(fName1));
        u2 = new Unit(Unit::ParseUnit(fName2));
    }
    catch (const std::string s)
    {
        std::cout << "File \"" << s << "\" not found!"
                  << std::endl;
        return 404;
    }

    u1->Attack(*u2);

    if (u1->IsDead())
        std::cout << u2->GetName() << " wins. Remaining HP: " << u2->GetHp() << std::endl;
    else
        std::cout << u1->GetName() << " wins. Remaining HP: " << u1->GetHp() << std::endl;

    delete u1;
    delete u2;

    return 0;
}