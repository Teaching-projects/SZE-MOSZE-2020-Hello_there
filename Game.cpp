#include "Game.h"

Game::Game()
    : hero(nullptr), map(nullptr)
{
}

Game::Game(const std::string &mapFileName)
    : hero(nullptr), map(new Map(mapFileName))
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
    if (monsters.size() > 0 || hero != nullptr)
        throw AlreadyHasUnitsException();

    map = m;
}

void Game::putHero(Hero *h, int x, int y)
{
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