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

    while (monsters.size() != 0 || hero->isAlive())
    {
        ShowMap();
    }

    if (hero->isAlive())
    {
        std::cout << hero->getName() + " cleared the map." << std::endl;
        // bemenet: folytatni akarod-e? ha igen újra Run
    }

    ResetGame();

    // loop here

    // hasStarted = false;
}

void Game::ShowMap() const
{
    int rowCount = map->GetRowCount();
    int colCount = map->GetColCount();

    std::cout << char(201);
    for (int i = 0; i < colCount; i++)
        std::cout << char(205) << char(205);
    std::cout << char(187) << std::endl;

    for (int i = 0; i < rowCount; i++)
    {
        std::cout << char(186);
        for (int j = 0; j < colCount; j++)
        {
            if (map->get(i, j) == Map::Free)
                std::cout << char(177) << char(177);
            else
                std::cout << char(219) << char(219);
        }
        std::cout << char(186) << std::endl;
    }

    std::cout << char(200);
    for (int i = 0; i < colCount; i++)
        std::cout << char(205) << char(205);
    std::cout << char(188) << std::endl;
}

void Game::ResetGame()
{
    if (hero != nullptr)
    {
        delete hero;
        hero = nullptr;
    }

    if (map != nullptr)
    {
        delete map;
        map = nullptr;
    }

    for (int i = 0; i < monsters.size(); i++)
    {
        delete monsters[i];
    }
    monsters.clear();

    hasStarted = false;
}