#include <iostream>
#include <vector>
#include "Unit.h"
#include "Player.h"

int main(int argc, char *argv[])
{
    std::string fName1 = argv[1];
    std::string fName2 = argv[2];

    Unit *u1;
    Unit *u2;

    try
    {
        if (std::string(argv[1]) == "player.json")
        {
            u1 = new Player(Unit::ParseUnit(fName1));
            u2 = new Unit(Unit::ParseUnit(fName2));
        }
        else if (std::string(argv[2]) == "player.json")
        {
            u1 = new Unit(Unit::ParseUnit(fName1));
            u2 = new Player(Unit::ParseUnit(fName2));
        }
        else
        {
            u1 = new Unit(Unit::ParseUnit(fName1));
            u2 = new Unit(Unit::ParseUnit(fName2));
        }
    }
    catch (const std::string s)
    {
        std::cout << "File \"" << s << "\" not found!"
                  << std::endl;
        return 404;
    }

	Unit::Fight(*u1, *u2);

    delete u1;
    delete u2;

    return 0;
}