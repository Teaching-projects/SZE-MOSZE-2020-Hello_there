#include "MarkedMap.h"

MarkedMap::MarkedMap(const std::string& filename):
Map(filename)
{
}

std::pair<int, int> MarkedMap::getHeroPosition() const
{
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'H') {
				return std::pair<int, int>(i, j);
			}
		}
	}
	throw WrongMapTypeException();
}

std::list<std::pair<int, int>> MarkedMap::getMonsterPositions(char c) const
{
	std::list<std::pair<int, int>> monsters;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == c) {
				monsters.push_back(std::pair(i, j));
			}
		}
	}
	if (monsters.empty()) throw WrongMapTypeException();
	return monsters;
}
