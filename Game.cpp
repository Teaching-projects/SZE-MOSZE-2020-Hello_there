#include "Game.h"

Game::Game()
{
}

Game::Game(const std::string &mapFileName)
{
    Map m(mapFileName);
    SetMap(&m);
}

void Game::SetMap(Map *m)
{
    map = m;
}