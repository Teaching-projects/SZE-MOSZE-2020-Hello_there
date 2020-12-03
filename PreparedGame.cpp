#include "PreparedGame.h"

PreparedGame::PreparedGame(std::string prepdGameName)
    : Game()
{
    JSON parser = JSON::parseFromFile("games/" + prepdGameName);
    std::string mapFile = parser.get<std::string>("map");
    MarkedMap *map = new MarkedMap(mapFile);
    SetMap(map);

    std::string heroFile = parser.get<std::string>("hero");
    Hero *h = Hero::parse(heroFile);
    std::pair<int, int> heroPos = map->getHeroPosition();
    PutHero(h, heroPos.first, heroPos.second);

    for (int i = 1; i < parser.GetDataCount(); i++)
    {
        std::string monster = "monster-" + std::to_string(i);
        if (parser.count(monster))
        {
            std::string monsterFile = parser.get<std::string>(monster);

            std::vector<std::pair<int, int>> monsterPositions;
            std::string sIdx = std::to_string(i);
            char cIdx = sIdx[0];

            monsterPositions = map->getMonsterPositions(cIdx);

            for (int j = 0; j < monsterPositions.size(); j++)
            {
                Monster *m = Monster::parse(monsterFile);
                PutMonster(m, monsterPositions[j].first, monsterPositions[j].second);
            }
        }
    }
}