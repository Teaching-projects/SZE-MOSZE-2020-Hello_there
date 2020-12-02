#include "PreparedGame.h"

void PreparedGame::Run()
{
    std::cout << "run" << std::endl;
}

PreparedGame::PreparedGame(std::string prepdGameName)
    : Game()
{
    JSON parser = JSON::parseFromFile("games/" + prepdGameName);
    std::string mapFile = parser.get<std::string>("map");
    MarkedMap *map = new MarkedMap(mapFile);
    SetMap(map);
    std::cout << "set map done" << std::endl;

    std::string heroFile = parser.get<std::string>("hero");
    Hero *h = Hero::parse(heroFile);
    std::pair<int, int> heroPos = map->getHeroPosition();
    std::cout << heroPos.first << " " << heroPos.second << std::endl;
    PutHero(h, heroPos.first, heroPos.second);
    std::cout << "put hero done" << std::endl;

    for (int i = 1; i < parser.GetDataCount(); i++)
    {
        std::string monster = "monster-" + std::to_string(i);
        if (parser.count(monster))
        {
            std::cout << "found a monster: " + monster << std::endl;
            std::string monsterFile = parser.get<std::string>(monster);
            std::cout << "found the monster file: " + monsterFile << std::endl;

            std::vector<std::pair<int, int>> monsterPositions;
            std::string sIdx = std::to_string(i);
            std::cout << "string is: " + sIdx << std::endl;
            char cIdx = sIdx[0];

            std::cout << "char is: "
                      << " " << cIdx << std::endl;
            monsterPositions = map->getMonsterPositions(cIdx);

            for (int j = 0; j < monsterPositions.size(); j++)
            {
                std::cout << "monster coordinates: " << monsterPositions[i].first << " " << monsterPositions[i].second << std::endl;
                Monster *m = Monster::parse(monsterFile);
                PutMonster(m, monsterPositions[i].first, monsterPositions[i].second);
                std::cout << "put monster done" << std::endl;
            }
        }
    }

    std::cout << "prepd game creation done" << std::endl;
}