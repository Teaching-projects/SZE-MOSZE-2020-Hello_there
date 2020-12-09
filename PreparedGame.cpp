#include "PreparedGame.h"

PreparedGame::PreparedGame(const std::string& prepdGameName)
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
	setFreeTexture("svgs/" + parser.get<std::string>("free_texture"));
	setWallTexture("svgs/" + parser.get<std::string>("wall_texture"));

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

            for (size_t j = 0; j < monsterPositions.size(); j++)
            {
                Monster *m = Monster::parse(monsterFile);
                PutMonster(m, monsterPositions[j].first, monsterPositions[j].second);
            }
        }
    }
}