#pragma once

#include <vector>
#include <iostream>
#include "Unit.h"

class DungeonMaster
{
private:
    std::vector<Unit *> units;

    DungeonMaster();

public:
    static DungeonMaster &GetInstance();
    void Init(char *argv[]);
    ~DungeonMaster();

    void Fight(Unit *atk, Unit *def);
};
