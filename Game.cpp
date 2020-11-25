#include "Game.h"

Game::Game()
{
}

Game::Game(const std::string &mapFileName)
{
    Map m(mapFileName);
    SetMap(&m);
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

void Game::SetMap(Map *m)
{
    map = m;
}