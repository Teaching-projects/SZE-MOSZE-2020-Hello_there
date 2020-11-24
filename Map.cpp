#include "Map.h"
#include <iostream>
#include <fstream>

Map::Map(const std::string &filename)
{
    std::string path = "maps/" + filename;
    std::ifstream mapstream(path);

    std::string line;
    while (std::getline(mapstream, line))
    {
        map.push_back(line);
    }
}

Map::type Map::get(const int x, const int y) const
{
    if (x >= map.size() || x < 0)
    {
        throw WrongIndexException();
    }
    else if (y >= map[x].length() || y < 0)
    {
        throw WrongIndexException();
    }

    std::string types = " #";
    return type(types.find(map[x][y]));
}