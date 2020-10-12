#include <iostream>
#include <vector>
#include "Unit.h"
#include "Player.h"

int main(int argc, char *argv[])
{
    std::string fName1 = argv[1];
    std::string fName2 = argv[2];
	Unit* u1;
	Unit* u2;
	if (std::string(argv[1]) == "player.json") {
		u1 = new Player(Unit::parseUnit(fName1));
		u2 = new Unit(Unit::parseUnit(fName2));
	}
	else if (std::string(argv[2])=="player.json") {
		u1 = new Unit(Unit::parseUnit(fName1));
		u2 = new Player(Unit::parseUnit(fName2));
	}
	else {
		u1 = new Unit(Unit::parseUnit(fName1));
		u2 = new Unit(Unit::parseUnit(fName2));
	}

    for (int turn = 0; !u1->IsDead() && !u2->IsDead(); turn++)
    {
		if (turn % 2 == 0)
			u2->Attack(*u1);
		else
			u1->Attack(*u2);
    }

	if (u1->IsDead()) {
		std::cout << u2->GetName() << " wins. Remaining HP: " << u2->GetHp() << std::endl;
	}
	else {
		std::cout << u1->GetName() << " wins. Remaining HP: " << u1->GetHp() << std::endl;
	}
	delete u1;
	delete u2;
    return 0;
}