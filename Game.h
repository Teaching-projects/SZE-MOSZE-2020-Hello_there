/**
 * @author Holdedve
 * @brief Game class
 * 
 * The Game class is responsible for running the game loop.
 * 
 * @date 2020-11-25
 */

#pragma once

#include <string>

class Game
{
private:
public:
    Game();

    /**
    * @brief Given a txt it returns the created game.
    * @param mapFileName Name of the txt, that contains the map.
    * @return Game
    */
    Game(const std::string &mapFileName);
};