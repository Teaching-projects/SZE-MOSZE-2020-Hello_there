/**
 * @author gfellnerm
 * @brief Map class
 * 
 * The map class is responsible for loading, accessing the map.
 * 
 * @date 2020-11-23
 */

#pragma once

#include <string>
#include <vector>

class Map
{
private:
    std::vector<std::string> map;

public:
    Map(std::string filename);
};