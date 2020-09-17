#include <iostream>
#include <vector>
#include <string>
#include "DungeonMaster.h"

int main(int argc, char *argv[])
{

    std::cout << std::endl;
    // Maple 150 10 Sally 45 30
    DungeonMaster *dm = DungeonMaster::GetInstance();
    dm->Init(argv);

    return 0;
}