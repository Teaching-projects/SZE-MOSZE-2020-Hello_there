#include <iostream>
#include <vector>
#include "Unit.h"
#include "Player.h"

int main(int argc, char *argv[])
{
    std::string fName1 = argv[1];
    std::string fName2 = argv[2];
	Player p(Unit::parseUnit(fName1));
    Unit u2 = Unit::parseUnit(fName2);

    for (int turn = 0; !p.IsDead() && !u2.IsDead(); turn++)
    {
		if (turn % 2 == 0)
			p.Defend(u2);
		else {
			p.addXp(u2.Defend(p));
			p.LvlUp();
		}
    }

    if (p.IsDead())
        std::cout << u2.GetName() << " wins. Remaining HP: " << u2.GetHp() << std::endl;
    else
        std::cout << p.GetName() << " wins. Remaining HP: " << p.GetHp() << std::endl;
    return 0;
}