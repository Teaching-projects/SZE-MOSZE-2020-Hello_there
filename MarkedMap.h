/**
 * \author BakiHUN
 * \brief Hero class
 *
 * The MarkedMap class is responsible for managing MarkedMaps.
 *
 * \date 2020-12-09
 */
#pragma once
#include "Map.h"
#include <iostream>

class MarkedMap : public Map
{
public:
	/**
	* @brief Retruns a MarkedMap from a file.
	* @param filename The name of the file which proved the map.
	* @return MarkedMap
	*/
	explicit MarkedMap(const std::string &filename);
	/**
	* @brief Retruns the position of the hero on the map.
	* @return void
	*/
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
