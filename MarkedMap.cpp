#include "MarkedMap.h"
#include <iostream>
MarkedMap::MarkedMap(const std::string &filename) : Map(filename)
{
}

std::pair<int, int> MarkedMap::getHeroPosition() const
{
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 'H')
			{
				return std::pair<int, int>(i, j);
			}
			
		}
	}
	throw WrongMapTypeException();
}


std::vector<std::pair<int, int>> MarkedMap::getMonsterPositions(char c) const
{
	std::vector<std::pair<int, int>> positions;
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == c)
			{
				positions.push_back(std::pair(i, j));
			}
		}
	}
	if (positions.empty())
		throw WrongMapTypeException();
	return positions;
}

