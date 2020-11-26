#include "Game.h"

Game::Game()
    : hero(nullptr), map(nullptr), hasStarted(false)
{
}

Game::Game(const std::string &mapFileName)
    : hero(nullptr), map(new Map(mapFileName)), hasStarted(false)
{
}

Game::~Game()
{
    if (hero != nullptr)
        delete hero;

    if (map != nullptr)
        delete map;

    for (int i = 0; i < monsters.size(); i++)
    {
        delete monsters[i];
    }
    monsters.clear();
}

void Game::SetMap(Map *m)
{
    if (hasStarted)
        throw GameAlreadyStartedException();

    if (monsters.size() > 0 || hero != nullptr)
        throw AlreadyHasUnitsException();

    map = m;
}

void Game::PutHero(Hero *h, int x, int y)
{
    if (hasStarted)
        throw GameAlreadyStartedException();

    if (map == nullptr)
        throw Map::WrongIndexException();

    if (hero != nullptr)
        throw AlreadyHasHeroException();

    if (!TileIsFree(x, y))
        throw OccupiedException();

    hero = h;
    hero->SetCoordinates(x, y);
}

bool Game::TileIsFree(int x, int y) const
{
    if (map->get(x, y) == Map::Free)
        return true;

    return false;
}

void Game::Run()
{
    if (map == nullptr || hero == nullptr)
        throw NotInitializedException{};

    hasStarted = true;
}