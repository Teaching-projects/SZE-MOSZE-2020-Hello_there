#include "Map.h"
#include <iostream>
#include <fstream>

Map::Map(std::string filename)
{
    std::ifstream mapstream(filename);
    std::string line;
    while (std::getline(mapstream, line))
    {
        map.push_back(line);
    }
}