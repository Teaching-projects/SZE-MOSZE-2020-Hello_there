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
#include "Map.h"
#include "Hero.h"

class Game
{
private:
    Map *map;
    std::vector<Monster *> monsters; // monsters placed on the map
    Hero *hero;

public:
    /**
    * @brief Returns an empty game, where the map isn't set.
    * @return Game
    */
    Game();

    /**
    * @brief Given a txt it returns the a game, with the map set.
    * @param mapFileName Name of the txt, that contains the map.
    * @return Game
    */
    Game(const std::string &mapFileName);

    /**
    * @brief Sets the given map to this game.
    * @param map The map that will be set to this game.
    * @return void
    */
    void SetMap(Map *map);

    /**
    * @brief Places the hero on the given coordinates.
    * @param hero the hero to be placed.
    * @param x row.
    * @param y col.
    * @return void
    */
    void putHero(Hero hero, int x, int y);
};