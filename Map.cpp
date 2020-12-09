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
    mapstream.close();
}

Map::type Map::get(const int x, const int y) const
{
    size_t x_ = x;
    size_t y_ = y;
    if (x_ >= map.size())
    {
        throw WrongIndexException();
    }
    else if (y_ >= map[x_].length())
    {
        throw WrongIndexException();
    }

    std::string types = " #";
    return type(types.find(map[x_][y_]));
}

int Map::GetRowCount() const
{
    return map.size();
}

int Map::GetColCount(int row) const
{
    return map[row].length();
}
