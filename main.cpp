#include <iostream>
#include <vector>
#include <string>
#include "Unit.h"

int main(int argc, char *argv[])
{
    Unit u1 = Unit(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
    Unit u2 = Unit(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

    for (int turn = 0; !u1.IsDead() && !u2.IsDead(); turn++)
    {
        std::cout << u1.ToString();
        std::cout << u2.ToString();

        if (turn % 2 == 0)
            u1.Defend(u2);
        else
            u2.Defend(u1);
    }

    std::cout << u1.ToString();
    std::cout << u2.ToString();

    if (u1.IsDead())
        std::cout << u1.GetName() << " died. " << u2.GetName() << " wins." << std::endl;
    else
        std::cout << u2.GetName() << " died. " << u1.GetName() << " wins." << std::endl;

    return 0;
}