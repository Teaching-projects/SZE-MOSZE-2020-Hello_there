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

    for (int i = 0; i < monsters.size(); i++)
    {
        delete monsters[i];
    }
    monsters.clear();
}

void Game::setWallTexture(std::string s)
{
    wallTexture = s;
}

void Game::setFreeTexture(std::string s)
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
        return;
    }

    hasStarted = true;

    while (42)
    {
        LookForFights();
        // ShowMap();
        for (std::list<Renderer *>::iterator it = renderers.begin(); it != renderers.end(); it++)
        {
            (*it)->render(*this);
        }

        if (monsters.size() != 0 && hero->isAlive())
            ReadUserInput();
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

    //ResetGame();
}

void Game::LookForFights()
{
    // if the hero and a monster/monsters are on same tile they fight

    int heroX = hero->GetXCoo();
    int heroY = hero->GetYCoo();

    std::vector<std::pair<int, int>> monsterCoordinates = GetMonsterCoordinates();
    std::vector<int> deadMonsters;

    // look for monsters on hero's tile
    for (int i = 0; i < monsterCoordinates.size(); i++)
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
    for (int i = 0; i < monsters.size(); i++)
    {
        bool dead = false;
        for (int j = 0; j < deadMonsters.size(); j++)
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

    for (int i = 0; i < monsters.size(); i++)
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

void Game::ShowMap() const
{
    int rowCount = map->GetRowCount();
    int colCount;

    std::vector<std::vector<char>> tiles(rowCount);

    for (int i = 0; i < rowCount; i++)
    {
        colCount = map->GetColCount(i);
        tiles[i] = std::vector<char>(colCount);

        for (int j = 0; j < colCount; j++)
        {
            if (map->get(i, j) == Map::Wall)
                tiles[i][j] = (char)(219);
            else
                tiles[i][j] = (char)(177);
        }
    }

    std::vector<std::pair<int, int>> monsterCoordinates = GetMonsterCoordinates();

    // place hero
    int x = hero->GetXCoo();
    int y = hero->GetYCoo();
    tiles[x][y] = 'H';

    // print top border of map
    colCount = map->GetColCount(0);
    std::cout << char(201);
    for (int i = 0; i < colCount; i++)
        std::cout << char(205) << char(205);
    std::cout << char(187) << std::endl;

    // print middle part
    for (int i = 0; i < rowCount; i++)
    {
        colCount = map->GetColCount(i);
        std::cout << char(186);
        for (int j = 0; j < colCount; j++)
        {
            char tile = tiles[i][j];

            int tileMonsterCount = 0;
            for (int k = 0; k < monsters.size(); k++)
            {
                if (monsterCoordinates[k].first == i && monsterCoordinates[k].second == j)
                    tileMonsterCount++;
            }

            if (tileMonsterCount > 1)
                std::cout << 'M' << 'M';
            else if (tileMonsterCount == 1)
                std::cout << 'M' << ' ';
            else if (tile == 'H')
                std::cout << tile << ' ';
            else
                std::cout << tile << tile;
        }
        std::cout << char(186) << std::endl;
    }

    // print bottom part of the map
    colCount = map->GetColCount(rowCount - 1);
    std::cout << char(200);
    for (int i = 0; i < colCount; i++)
        std::cout << char(205) << char(205);
    std::cout << char(188) << std::endl;
}
void Game::HeroPerspective() const
{
    int rowCount = map->GetRowCount();
    int colCount;

    std::vector<std::vector<char>> tiles(rowCount);

    for (int i = 0; i < rowCount; i++)
    {
        colCount = map->GetColCount(i);
        tiles[i] = std::vector<char>(colCount);

        for (int j = 0; j < colCount; j++)
        {
            if (map->get(i, j) == Map::Wall)
                tiles[i][j] = (char)(219);
            else
                tiles[i][j] = (char)(177);
        }
    }

    std::vector<std::pair<int, int>> monsterCoordinates = GetMonsterCoordinates();

    // place hero
    int x = hero->GetXCoo();
    int y = hero->GetYCoo();
    tiles[x][y] = 'H';
    int maxSteps = hero->getLightRadius() * 2 + 1;
    if (maxSteps >= colCount)
        maxSteps = colCount;
    int startRow = x;
    int startCol = y;
    for (int i = 0; i < hero->getLightRadius() && startRow > 0 && startRow < rowCount; i++)
    {
        startRow--;
    }
    for (int i = 0; i < hero->getLightRadius() && startCol > 0 && startCol < colCount; i++)
    {
        startCol--;
    }
    int magic = (colCount - startCol);

    // print top border of map
    std::cout << char(201);
    for (int i = 0; i < maxSteps && i < magic; i++)
        std::cout << char(205) << char(205);
    std::cout << char(187) << std::endl;
    // print middle part
    for (int i = 0, row = startRow; i < maxSteps && row < rowCount; i++)
    {
        std::cout << char(186);
        for (int j = 0, col = startCol; j < maxSteps && col < colCount; j++)
        {
            char tile = tiles[row][col];

            int tileMonsterCount = 0;
            for (int k = 0; k < monsters.size(); k++)
            {
                if (monsterCoordinates[k].first == row && monsterCoordinates[k].second == col)
                    tileMonsterCount++;
            }

            if (tileMonsterCount > 1)
                std::cout << 'M' << 'M';
            else if (tileMonsterCount == 1)
                std::cout << 'M' << ' ';
            else if (tile == 'H')
                std::cout << tile << ' ';
            else
                std::cout << tile << tile;
            col++;
        }
        std::cout << char(186) << std::endl;
        row++;
    }

    // print bottom part of the map
    std::cout << char(200);
    for (int i = 0; i < maxSteps && i < magic; i++)
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
std::string Game::getMonsterTextureInField(int x, int y) const
{
    for (std::vector<Monster *>::const_iterator it = monsters.begin(); it != monsters.end(); it++)
    {
        if ((*it)->GetXCoo() == x && (*it)->GetYCoo() == y)
        {
            return (*it)->GetTexture();
        }
    }
    return "";
}