#pragma once
#include "Map.h"

class MarkedMap : public Map
{
public:
	MarkedMap(const std::string &filename);
	std::pair<int, int> getHeroPosition() const;
	std::vector<std::pair<int, int>> getMonsterPositions(char c) const;

	class WrongMapTypeException : std::exception
	{
	public:
		/**
		* @brief thrown when there is no hero or monsters on the map
		*/
		WrongMapTypeException() {}
	};
};
