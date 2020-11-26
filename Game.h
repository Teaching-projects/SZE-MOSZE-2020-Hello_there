/**
 * \author Holdedve
 * \brief Game class
 * 
 * The Game class is responsible for running the game loop.
 * 
 * \date 2020-11-25
 */

#pragma once

#include "Map.h"
#include "Hero.h"

class Game
{
private:
    Map *map;
    std::vector<Monster *> monsters; // monsters placed on the map
    Hero *hero;
    bool hasStarted;

    bool TileIsFree(int x, int y) const;

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

    ~Game();

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

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
    void PutHero(Hero *h, int x, int y);

    void Run();

    class AlreadyHasUnitsException : std::exception
    {
    public:
        /**
        * @brief thrown when map already has Units and 
        * SetMap for a new map is called
        */
        AlreadyHasUnitsException() {}
    };

    class AlreadyHasHeroException : std::exception
    {
    public:
        /**
        * @brief thrown when hero already exists in the game
        */
        AlreadyHasHeroException() {}
    };

    class OccupiedException : std::exception
    {
    public:
        /**
        * @brief thrown when trying to put unit on wall
        */
        OccupiedException() {}
    };

    class NotInitializedException : std::exception
    {
    public:
        /**
        * @brief thrown when either hero or map isn't set when trying run the game
        */
        NotInitializedException() {}
    };

    class GameAlreadyStartedException : std::exception
    {
    public:
        /**
        * @brief thrown when trying to put hero or set map when the game has already started
        */
        GameAlreadyStartedException() {}
    };
};