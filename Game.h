/**
 * \author Holdedve
 * \brief Game class
 * 
 * The Game class is responsible for running the game loop.
 * 
 * \date 2020-11-25
 */

#pragma once

#include "MarkedMap.h"
#include "Hero.h"
#include "Renderer.h"
class Renderer;
class Game
{
private:
    Map *map;
    std::vector<Monster *> monsters; // monsters placed on the map
    Hero *hero;
    bool hasStarted;
    std::list<Renderer *> renderers;
    bool TileIsFree(int x, int y) const;
    void ResetGame();
    void ReadUserInput();
    void SetCoordinateDifs(char way, int &difX, int &difY) const;
    void LookForFights();
    std::string wallTexture;
    std::string freeTexture;
    void HeroStatus();

public:
    std::vector<std::pair<int, int>> GetMonsterCoordinates() const;
    Hero *getHero() const;
    int getMonsterCount() const;
    void registerRenderer(Renderer *);
    std::string getFreeTexture() const;
    std::string getWallTexture() const;
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
    explicit Game(Map *m);
    /**
	* @brief Given a txt it returns the a game, with the map set.
	* @param mapFileName Name of the txt, that contains the map.
	* @return Game
	*/
    explicit Game(MarkedMap *m);

    ~Game();

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    /**
	* @brief Sets the given svg file as the wall texture for this game.
	* @param std::string the name of the file to use as wall texture.
	* @return void
	*/
    void setWallTexture(const std::string &);

    /**
	* @brief Sets the given svg file as the wall texture for this game.
	* @param std::string the name of the file to use as wall texture.
	* @return void
	*/
    void setFreeTexture(const std::string &);

    /**
    * @brief Sets the given map to this game.
    * @param map The map that will be set to this game.
    * \throw GameAlreadyStartedException
    * \throw AlreadyHasUnitsException
    * @return void
    */
    void SetMap(Map *map);

    /**
    * @brief Places the hero on the given coordinates.
    * @param h the hero to be placed.
    * @param x row.
    * @param y col.
    * \throw GameAlreadyStartedException
    * \throw Map::WrongIndexException
    * \throw AlreadyHasHeroException
    * \throw OccupiedException
    * @return void
    */
    void PutHero(Hero *h, int x, int y);

    /**
    * @brief Places the monster on the given coordinates.
    * @param m the monster to be placed.
    * @param x row.
    * @param y col.
    * \throw OccupiedException
    * @return void
    */
    void PutMonster(Monster *m, int x, int y);
    /**
	* @brief Returns with the current map of the game.
	* @return Map*
	*/
    Map *getMap() const;
    /**
    * @brief Starts the gameplay loop. Handles fighting, user input, moving.
    * \throw NotInitializedException
    * @return void
    */
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

    class HeroIsNullptrException : std::exception
    {
    public:
        /**
        * @brief thrown when hero is nullptr when it shouldn't be
        */
        HeroIsNullptrException() {}
    };
    std::string getMonsterTextureInField(int x, int y) const;
};