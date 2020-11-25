#include "Game.h"

Game::Game()
    : hero(nullptr), map(nullptr)
{
}

Game::Game(const std::string &mapFileName)
    : hero(nullptr), map(nullptr)
{
    Map m(mapFileName);
    SetMap(m);
}

Game::~Game()
{
    delete hero;

    for (int i = 0; i < monsters.size(); i++)
    {
        delete monsters[i];
    }
    monsters.clear();
}

void Game::SetMap(Map m)
{
    map = m;
}