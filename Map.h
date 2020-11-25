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
    /**
    * @brief Contains the map, each line is a string.
    */
    std::vector<std::string> map;

public:
    /**
    * @brief The types that a given point of the map can be. 
    */
    enum type
    {
        Free,
        Wall
    };

    /**
    * @brief Given a txt it returns the generated map.
    * @param filename Name of the txt file
    * @return Map
    */
    Map(const std::string &filename);

    /**
    * @brief Returns the type of the tile.
    * @param x row
    * @param y column
    * @return Map::type
    */
    Map::type get(const int x, const int y) const;

    /**
    * @brief Custom exception class.
    */
    class WrongIndexException : std::exception
    {
    public:
        /**
        * @brief Constructor for the exception.
        */
        WrongIndexException() {}
    };
};