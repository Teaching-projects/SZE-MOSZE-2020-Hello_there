#include <iostream>
#include <vector>
#include <string>
#include "Unit.h"

int main(int argc, char *argv[])
{
    Unit u1 = Unit::parseUnit(argv[1]);
	Unit u2 = Unit::parseUnit(argv[2]);

    for (int turn = 0; !u1.IsDead() && !u2.IsDead(); turn++)
    {
        //std::cout << u1.ToString();
        //std::cout << u2.ToString();

        if (turn % 2 == 0)
            u1.Defend(u2);
        else
            u2.Defend(u1);
    }

    //std::cout << u1.ToString();
    //std::cout << u2.ToString();

    if (u1.IsDead())
        std::cout << u2.GetName() << " wins. Remaining HP: "<<u2.GetHp() << std::endl;
    else
        std::cout << u1.GetName() << " wins. Remaining HP: " <<u1.GetHp() << std::endl;

    return 0;
}