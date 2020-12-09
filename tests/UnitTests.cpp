#include "gtest/gtest.h"
#include "../JSON.h"
#include "../Monster.h"
#include "../Hero.h"
#include "../Map.h"
#include "../Game.h"
#include "../MarkedMap.h"
#include "../PreparedGame.h"

#include "../HeroTextRenderer.h"
#include "../HeroSVGRenderer.h"
#include "../ObserverTextRenderer.h"
#include "../ObserverSVGRenderer.h"
#include <fstream>

TEST(ParserTest, CheckMapContent)
{
    std::ifstream vaderFile("units/vader.json");
    JSON vaderJSON = JSON::parseFromStream(vaderFile);
    EXPECT_EQ("Vader", vaderJSON.get<std::string>("name"));
    EXPECT_EQ(666, vaderJSON.get<int>("health_points"));
    EXPECT_EQ(42, vaderJSON.get<int>("damage"));
    EXPECT_EQ(15, vaderJSON.get<int>("defense"));
    EXPECT_EQ(6.9, vaderJSON.get<double>("attack_cooldown"));

    std::ifstream lukeFile("units/luke.json");
    JSON lukeJSON = JSON::parseFromStream(lukeFile);
    EXPECT_EQ("Luke", lukeJSON.get<std::string>("name"));
    EXPECT_EQ(100, lukeJSON.get<int>("health_points"));
    EXPECT_EQ(25, lukeJSON.get<int>("damage"));
    EXPECT_EQ(10, lukeJSON.get<int>("defense"));
    EXPECT_EQ(3.0, lukeJSON.get<double>("attack_cooldown"));

    std::ifstream palpatineFile("units/palpatine.json");
    JSON palpatineJSON = JSON::parseFromStream(palpatineFile);
    EXPECT_EQ("Palpatine", palpatineJSON.get<std::string>("name"));
    EXPECT_EQ(111, palpatineJSON.get<int>("health_points"));
    EXPECT_EQ(21, palpatineJSON.get<int>("damage"));
    EXPECT_EQ(5, palpatineJSON.get<int>("defense"));
    EXPECT_EQ(2.5, palpatineJSON.get<double>("attack_cooldown"));
}

TEST(ParserTest, ExpectExceptions)
{
    std::ifstream messyUnit("units/messy_unit.json");
    EXPECT_THROW(JSON::parseFromStream(messyUnit), const char *);

    const char *messyUnit2 = "units/messy_unit2.json";
    EXPECT_THROW(JSON::parseFromFile(messyUnit2), const char *);

    const char *messyUnit3 = "units/messy_unit3.json";
    EXPECT_THROW(JSON::parseFromFile(messyUnit3), const char *);
}

TEST(ParserTest, ExpectNoExceptions)
{
    std::ifstream vaderFile("units/vader.json");
    EXPECT_NO_THROW(JSON::parseFromStream(vaderFile));

    const char *lukeFile = "units/luke.json";
    EXPECT_NO_THROW(JSON::parseFromFile(lukeFile));

    const char *palpatineFile = "units/palpatine.json";
    EXPECT_NO_THROW(JSON::parseFromFile(palpatineFile));
}

TEST(UnitClassTest, SuccessfulConstruction)
{
    EXPECT_NO_THROW(std::string("units/vader.json"));

    EXPECT_NO_THROW(std::string("units/palpatine.json"));

    EXPECT_NO_THROW(std::string("units/luke.json"));
}

TEST(PlayerClassTest, SuccessfulConstruction)
{
    std::string playerFile = "Dark_Wanderer.json";
    EXPECT_NO_THROW(Hero::parse(playerFile));
}

TEST(UnitClassTest, NoCrazyValues)
{
    std::string vaderFile = "vader.json";
    Monster *vader(Monster::parse(vaderFile));

    ASSERT_TRUE(vader->getDamage() > 0);
    ASSERT_TRUE(vader->getAttackCoolDown() > 0);
    ASSERT_TRUE(vader->getHealthPoints() > 0);
    ASSERT_TRUE(vader->getDefense() >= 0);

    std::string palpatineFile = "palpatine.json";
    Monster *palpatine(Monster::parse(palpatineFile));

    ASSERT_TRUE(palpatine->getDamage() > 0);
    ASSERT_TRUE(palpatine->getAttackCoolDown() > 0);
    ASSERT_TRUE(palpatine->getHealthPoints() > 0);
    ASSERT_TRUE(palpatine->getDefense() >= 0);

    std::string lukeFile = "luke.json";
    Monster *luke(Monster::parse(lukeFile));

    ASSERT_TRUE(luke->getDamage() > 0);
    ASSERT_TRUE(luke->getAttackCoolDown() > 0);
    ASSERT_TRUE(luke->getHealthPoints() > 0);
    ASSERT_TRUE(luke->getDefense() >= 0);

    std::string playerFile = "player.json";
    Monster *player(Monster::parse(playerFile));

    ASSERT_TRUE(player->getDamage() > 0);
    ASSERT_TRUE(player->getAttackCoolDown() > 0);
    ASSERT_TRUE(player->getHealthPoints() > 0);
    ASSERT_TRUE(player->getDefense() >= 0);
}

TEST(ParserTest, IndifferentToSpaces)
{
    std::ifstream vaderFile("units/vader.json");
    JSON vaderJSON = JSON::parseFromStream(vaderFile);
    std::ifstream vaderFileLookalike("units/vader_lookalike.json");
    JSON vaderJSONLookalike = JSON::parseFromStream(vaderFileLookalike);
    EXPECT_TRUE(JSON::compareJSON(vaderJSON, vaderJSONLookalike));

    std::ifstream lukeFile("units/luke.json");
    JSON lukeJSON = JSON::parseFromStream(lukeFile);
    std::ifstream lukeFileLookalike("units/luke_lookalike.json");
    JSON lukeJSONLookalike = JSON::parseFromStream(lukeFileLookalike);
    EXPECT_TRUE(JSON::compareJSON(lukeJSON, lukeJSONLookalike));

    std::ifstream palpatineFile("units/palpatine.json");
    JSON palpatineJSON = JSON::parseFromStream(palpatineFile);
    std::ifstream palpatineFileLookalike("units/palpatine_lookalike.json");
    JSON palpatineJSONLookalike = JSON::parseFromStream(palpatineFileLookalike);
    EXPECT_TRUE(JSON::compareJSON(palpatineJSON, palpatineJSONLookalike));

    std::ifstream playerFile("units/player.json");
    JSON playerJSON = JSON::parseFromStream(playerFile);
    std::ifstream playerFileLookalike("units/player_lookalike.json");
    JSON playerJSONLookalike = JSON::parseFromStream(playerFileLookalike);
    EXPECT_TRUE(JSON::compareJSON(playerJSON, playerJSONLookalike));
}

TEST(ParserTest, ExpectException)
{
    std::string content = "this is a very bad json content";
    EXPECT_ANY_THROW(JSON::parseFromString(content));
}

TEST(ParserTest, IndifferentToKeyOrder)
{
    std::ifstream vaderFile("units/vader.json");
    JSON vaderJSON = JSON::parseFromStream(vaderFile);
    std::ifstream vaderFileLookalike("units/vader_lookalike2.json");
    JSON vaderJSONLookalike = JSON::parseFromStream(vaderFileLookalike);
    EXPECT_TRUE(JSON::compareJSON(vaderJSON, vaderJSONLookalike));

    std::ifstream lukeFile("units/luke.json");
    JSON lukeJSON = JSON::parseFromStream(lukeFile);
    std::ifstream lukeFileLookalike("units/luke_lookalike2.json");
    JSON lukeJSONLookalike = JSON::parseFromStream(lukeFileLookalike);
    EXPECT_TRUE(JSON::compareJSON(lukeJSON, lukeJSONLookalike));

    std::ifstream palpatineFile("units/palpatine.json");
    JSON palpatineJSON = JSON::parseFromStream(palpatineFile);
    std::ifstream palpatineFileLookalike("units/palpatine_lookalike2.json");
    JSON palpatineJSONLookalike = JSON::parseFromStream(palpatineFileLookalike);
    EXPECT_TRUE(JSON::compareJSON(palpatineJSON, palpatineJSONLookalike));

    std::ifstream playerFile("units/player.json");
    JSON playerJSON = JSON::parseFromStream(playerFile);
    std::ifstream playerFileLookalike("units/player_lookalike2.json");
    JSON playerJSONLookalike = JSON::parseFromStream(playerFileLookalike);
    EXPECT_TRUE(JSON::compareJSON(playerJSON, playerJSONLookalike));
}

TEST(MapTest, SuccessfulConstruction)
{
    EXPECT_NO_THROW(Map("map_1.txt"));
}

TEST(MapTest, HandleWrongIndex)
{
    Map m("map_1.txt");
    int bigX = 666;
    int bigY = 666;

    EXPECT_ANY_THROW(m.get(bigX, bigY));

    int negX = -420;
    int negY = -420;
    EXPECT_ANY_THROW(m.get(negX, negY));
}

TEST(MapTest, CorrectIndexNoThrow)
{
    Map m("map_1.txt");
    int x = 4;
    int y = 2;

    EXPECT_NO_THROW(m.get(x, y));
}

TEST(GameTest, SuccessfulConstruction)
{
    Map *m = new Map("map_1.txt");
    EXPECT_NO_THROW(Game(m));
}

TEST(GameTest, MethodTestExpectNoThrow)
{
    Map *m = new Map("map_1.txt");
    Game g(m);
    Map *m2 = new Map("map_2.txt");
    delete m;

    EXPECT_NO_THROW(g.SetMap(m2));

    Hero *h = new Hero("Joe", 500, 10, 12.0, 2, "Hero.svg", 30, 10, 2, 1.2, 1, 2, 5);
    EXPECT_NO_THROW(g.PutHero(h, 1, 1));
}

TEST(GameTest, MethodTestExpectThrow)
{
    EXPECT_THROW({
        try
        {
            Game g;
            Hero *h = new Hero("Joe", 500, 10, 12.0, 2, "Hero.svg", 30, 10, 2, 1.2, 1, 2, 5);
            g.PutHero(h, 0, 0);
        }
        catch (const Map::WrongIndexException &e)
        {
            throw;
        } }, Map::WrongIndexException);

    EXPECT_THROW({
        try
        {
			Map* m = new Map("map_1.txt");
            Game g(m);
            Hero *h = new Hero("Joe", 500, 10, 12.0, 2, "Hero.svg", 30, 10, 2, 1.2, 1, 2, 5);
            g.PutHero(h, 1, 1);
            g.PutHero(h, 1, 2);
        }
        catch (const Game::AlreadyHasHeroException &e)
        {
            throw;
        } }, Game::AlreadyHasHeroException);

    EXPECT_THROW({
        try
        {
			Map* m = new Map("map_1.txt");
            Game g(m);
            Hero *h = new Hero("Joe", 500, 10, 12.0, 2, "Hero.svg", 30, 10, 2, 1.2, 1, 2, 5);
            g.PutHero(h, 0, 0);
        }
        catch (const Game::OccupiedException &e)
        {
            throw;
        } }, Game::OccupiedException);

    EXPECT_THROW({
        try
        {
			Map* m = new Map("map_1.txt");
            Game g(m);
            Hero *h = new Hero("Joe", 500, 10, 12.0, 2, "Hero.svg", 30, 10, 2, 1.2, 1, 2, 5);
            g.PutHero(h, 1, 1);

            Map *m2 = new Map("map_2.txt");
            g.SetMap(m2);
        }
        catch (const Game::AlreadyHasUnitsException &e)
        {
            throw;
        } }, Game::AlreadyHasUnitsException);

    EXPECT_THROW({
        try
        {
			Map* m = new Map("map_1.txt");
            Game g(m);
            g.Run();
        }
        catch (const Game::NotInitializedException &e)
        {
            throw;
        } }, Game::NotInitializedException);
}
TEST(MarkedMapTest, ConstructionExceptionThrown)
{
    EXPECT_THROW({
		try
		{
			MarkedMap m("map_1.txt");
			m.getHeroPosition();
		}
		catch (const MarkedMap::WrongMapTypeException& e)
		{
			throw;
		} }, MarkedMap::WrongMapTypeException);
    EXPECT_THROW({
		try
		{
		MarkedMap m("map_1.txt");
		m.getMonsterPositions('1');
		}
		catch (const MarkedMap::WrongMapTypeException& e)
		{
		throw;
		} }, MarkedMap::WrongMapTypeException);
}

TEST(MarkedMapTest, ConstructionNoExceptionThrown)
{
    MarkedMap m("marked_map.txt");
    EXPECT_NO_THROW(m.getHeroPosition());

    EXPECT_NO_THROW(m.getMonsterPositions('1'));
}

TEST(PreparedGameTest, ConstructionNoExceptionThrown)
{
    EXPECT_NO_THROW(PreparedGame g("prepd_game_1.json"));
}

TEST(PreparedGameTest, ExpectExceptionThrow)
{
    EXPECT_ANY_THROW(PreparedGame g("missing_map.txt"));
}

TEST(PreparedGameTest, MethodTests)
{
    MarkedMap *m = new MarkedMap("marked_map.txt");
    Game g(m);
    Hero *h = new Hero("Joe", 500, 10, 12.0, 2, "Hero.svg", 30, 10, 2, 1.2, 1, 2, 5);
    g.PutHero(h, 1, 1);

    HeroTextRenderer hTxtRenderer("HeroTextOut.txt");
    hTxtRenderer.render(g);
    EXPECT_TRUE(std::ifstream("HeroTextOut.txt").good());

    HeroSVGRenderer hSvgRenderer("HeroSVGOut.txt");
    hSvgRenderer.render(g);
    EXPECT_TRUE(std::ifstream("HeroSVGOut.txt").good());

    ObserverTextRenderer oTxtRenderer("ObserverTextOut.txt");
    oTxtRenderer.render(g);
    EXPECT_TRUE(std::ifstream("ObserverTextOut.txt").good());

    ObserverSVGRenderer oSvgRenderer("ObserverSVGOut.txt");
    oSvgRenderer.render(g);
    EXPECT_TRUE(std::ifstream("ObserverSVGOut.txt").good());

    oSvgRenderer.setOutputStream("ObserverSVGOut_2.txt");
    oSvgRenderer.render(g);
    EXPECT_TRUE(std::ifstream("ObserverSVGOut_2.txt").good());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
