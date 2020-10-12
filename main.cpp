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

    for (int turn = 0; !u1->IsDead() && !u2->IsDead(); turn++)
    {
        if (turn % 2 == 0)
            u1->Defend(*u2);
        else
            u2->Defend(*u1);
    }

    if (u1->IsDead())
        std::cout << u2->GetName() << " wins. Remaining HP: " << u2->GetHp() << std::endl;
    else
        std::cout << u1->GetName() << " wins. Remaining HP: " << u1->GetHp() << std::endl;

    return 0;
}