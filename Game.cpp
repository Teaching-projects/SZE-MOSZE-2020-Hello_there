#include "Game.h"

Game::Game()
    : hero(nullptr), map(nullptr), hasStarted(false), freeTexture(""), wallTexture("")
{
}
Game::Game(Map *m)
    : hero(nullptr), map(m), hasStarted(false), freeTexture(""), wallTexture("")
{
}
Game::Game(MarkedMap *m)
    : hero(nullptr), map(m), hasStarted(false), freeTexture(""), wallTexture("")
{
}

Game::~Game()
{
    if (hero != nullptr)
        delete hero;

    if (map != nullptr)
        delete map;

    for (size_t i = 0; i < monsters.size(); i++)
    {
        delete monsters[i];
    }
    monsters.clear();
}

void Game::setWallTexture(const std::string &s)
{
    wallTexture = s;
}

void Game::setFreeTexture(const std::string &s)
{
    freeTexture = s;
}

void Game::SetMap(Map *m)
{
    if (hasStarted)
        throw GameAlreadyStartedException();

    if (monsters.size() > 0 || hero != nullptr)
        throw AlreadyHasUnitsException();

    map = m;
}

void Game::PutMonster(Monster *m, int x, int y)
{
    if (!TileIsFree(x, y))
        throw OccupiedException();

    monsters.push_back(m);
    m->SetCoordinates(x, y);
}

Map *Game::getMap() const
{
    return map;
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
    if (map->get(x, y) == Map::Wall)
        return false;

    return true;
}

void Game::Run()
{
    if (map == nullptr || hero == nullptr)
    {
        throw NotInitializedException{};
    }

    hasStarted = true;

    while (42)
    {
        LookForFights();
        // ShowMap();
        for (std::list<Renderer *>::iterator it = renderers.begin(); it != renderers.end(); it = std::next(it))
        {
            (*it)->render(*this);
        }

        if (monsters.size() != 0 && hero->isAlive())
        {
            HeroStatus();
            ReadUserInput();
        }
        else
            break;
    }

    if (hero->isAlive())
    {
        std::cout << hero->getName() + " cleared the map." << std::endl;
    }
    else
    {
        std::cout << hero->getName() + " died." << std::endl;
    }
}

void Game::LookForFights()
{
    // if the hero and a monster/monsters are on same tile they fight

    int heroX = hero->GetXCoo();
    int heroY = hero->GetYCoo();

    std::vector<std::pair<int, int>> monsterCoordinates = GetMonsterCoordinates();
    std::vector<int> deadMonsters;

    // look for monsters on hero's tile
    for (size_t i = 0; i < monsterCoordinates.size(); i++)
    {
        if (heroX == monsterCoordinates[i].first && heroY == monsterCoordinates[i].second)
        {
            hero->fightTilDeath(*monsters[i]);

            if (hero->isAlive() == false)
                break;
            else
                deadMonsters.push_back(i);
        }
    }

    // this is unreasonably complicated
    std::vector<Monster *> aliveMonsters;
    for (size_t i = 0; i < monsters.size(); i++)
    {
        bool dead = false;
        for (size_t j = 0; j < deadMonsters.size(); j++)
        {
            if (i == deadMonsters[j])
                dead = true;
        }

        if (!dead)
            aliveMonsters.push_back(monsters[i]);
    }

    // update monsters
    monsters = aliveMonsters;
    deadMonsters.clear();
}

void Game::HeroStatus()
{
    std::cout << "HP:" << hero->getHealthPoints() << " LVL:" << hero->getLevel() << std::endl;
}

void Game::ReadUserInput()
{
    // every feasible input is also correct, but not all correct inputs are feasible
    // Going (N)orth is correct but may not be feasible if there's a wall
    // Going (F)orth is incorrect (in this game) to begin with

    bool feasibleInput = false;
    bool correctInput = false;
    char ways[4] = {'N', 'E', 'S', 'W'};
    char way;

    int heroX = hero->GetXCoo();
    int heroY = hero->GetYCoo();
    int difX, difY;

    while (!feasibleInput)
    {
        while (!correctInput)
        {
            std::cout << "Which way do you wish to go?"
                         "\nType the first character: (N)orth (E)ast (S)outh (W)est"
                         "\nInput: ";
            std::cin >> way;

            for (int i = 0; i < 4; i++)
                if (way == ways[i])
                    correctInput = true;
            if (!correctInput)
                std::cout << "\nDid you type it correctly? I don't think so, please try again." << std::endl;
        }

        SetCoordinateDifs(way, difX, difY);

        if (map->get(heroX + difX, heroY + difY) != Map::Wall)
            feasibleInput = true;
        else
        {
            correctInput = false;
            std::cout << "That move is not feasible. There's an obstacle." << std::endl;
        }
    }

    // move hero
    hero->SetCoordinates(heroX + difX, heroY + difY);
}

void Game::SetCoordinateDifs(char way, int &difX, int &difY) const
{
    switch (way)
    {
    case 'N':
        difX = -1, difY = 0;
        break;
    case 'E':
        difX = 0, difY = 1;
        break;
    case 'S':
        difX = 1, difY = 0;
        break;
    case 'W':
        difX = 0, difY = -1;
        break;
    default:
        break;
    }
}

std::vector<std::pair<int, int>> Game::GetMonsterCoordinates() const
{
    std::vector<std::pair<int, int>> monsterCoordinates;

    for (size_t i = 0; i < monsters.size(); i++)
    {
        int x = monsters[i]->GetXCoo();
        int y = monsters[i]->GetYCoo();

        monsterCoordinates.push_back(std::pair(x, y));
    }

    return monsterCoordinates;
}

Hero *Game::getHero() const
{
    return hero;
}

int Game::getMonsterCount() const
{
    return monsters.size();
}

void Game::registerRenderer(Renderer *r)
{
    renderers.push_back(r);
}

std::string Game::getFreeTexture() const
{
    return freeTexture;
}

std::string Game::getWallTexture() const
{
    return wallTexture;
}

std::string Game::getMonsterTextureInField(int x, int y) const
{
    for (std::vector<Monster *>::const_iterator it = monsters.begin(); it != monsters.end(); it = std::next(it))
    {
        if ((*it)->GetXCoo() == x && (*it)->GetYCoo() == y)
        {
            return (*it)->GetTexture();
        }
    }
    return "";
}