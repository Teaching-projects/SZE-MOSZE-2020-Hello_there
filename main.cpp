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

    Unit *slowerUnit;
    Unit *fasterUnit;

    if (u1->GetAtkCoolDown() < u2->GetAtkCoolDown())
    {
        fasterUnit = u1;
        slowerUnit = u2;
    }
    else
    {
        fasterUnit = u2;
        slowerUnit = u1;
    }

    u1->Attack(*u2);
    u2->Attack(*u1);
    float slowerUnitTimer = 0.0;

    for (slowerUnitTimer += fasterUnit->GetAtkCoolDown(); !fasterUnit->IsDead() && !slowerUnit->IsDead(); slowerUnitTimer += fasterUnit->GetAtkCoolDown())
    {
        if (slowerUnitTimer > slowerUnit->GetAtkCoolDown())
        {
            fasterUnit->Attack(*slowerUnit);
            if (!fasterUnit->IsDead())
                slowerUnit->Attack(*fasterUnit);
            slowerUnitTimer -= slowerUnit->GetAtkCoolDown();
        }
        else if (slowerUnitTimer == slowerUnit->GetAtkCoolDown())
        {
            u2->Attack(*u1);
            if (!u2->IsDead())
                u1->Attack(*u2);
            slowerUnitTimer = 0.0;
        }
        else
        {
            slowerUnit->Attack(*fasterUnit);
        }
    }

    if (u1->IsDead())
        std::cout << u2->GetName() << " wins. Remaining HP: " << u2->GetHp() << std::endl;
    else
        std::cout << u1->GetName() << " wins. Remaining HP: " << u1->GetHp() << std::endl;

    delete u1;
    delete u2;

    return 0;
}