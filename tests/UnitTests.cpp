#include "gtest/gtest.h"
#include "../JSON.h"
#include "../Monster.h"
#include "../Hero.h"
#include "../Map.h"
#include "../Game.h"

TEST(ParserTest, CheckMapContent)
{
    std::ifstream vaderFile("units/vader.json");
    JSON vaderJSON = JSON::parseFromStream(vaderFile);
    EXPECT_EQ("Vader", vaderJSON.get<std::string>("name"));
    EXPECT_EQ(666, vaderJSON.get<int>("health_points"));
    EXPECT_EQ(42, vaderJSON.get<int>("damage"));
    EXPECT_EQ(6.9f, vaderJSON.get<float>("attack_cooldown"));

    std::ifstream lukeFile("units/luke.json");
    JSON lukeJSON = JSON::parseFromStream(lukeFile);
    EXPECT_EQ("Luke", lukeJSON.get<std::string>("name"));
    EXPECT_EQ(100, lukeJSON.get<int>("health_points"));
    EXPECT_EQ(25, lukeJSON.get<int>("damage"));
    EXPECT_EQ(3.0f, lukeJSON.get<float>("attack_cooldown"));

    std::ifstream palpatineFile("units/palpatine.json");
    JSON palpatineJSON = JSON::parseFromStream(palpatineFile);
    EXPECT_EQ("Palpatine", palpatineJSON.get<std::string>("name"));
    EXPECT_EQ(111, palpatineJSON.get<int>("health_points"));
    EXPECT_EQ(21, palpatineJSON.get<int>("damage"));
    EXPECT_EQ(2.5f, palpatineJSON.get<float>("attack_cooldown"));
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
    Monster vader(Monster::parse(vaderFile));

    ASSERT_TRUE(vader.getDamage() > 0);
    ASSERT_TRUE(vader.getAttackCoolDown() > 0);
    ASSERT_TRUE(vader.getHealthPoints() > 0);

    std::string palpatineFile = "palpatine.json";
    Monster palpatine(Monster::parse(palpatineFile));

    ASSERT_TRUE(palpatine.getDamage() > 0);
    ASSERT_TRUE(palpatine.getAttackCoolDown() > 0);
    ASSERT_TRUE(palpatine.getHealthPoints() > 0);

    std::string lukeFile = "luke.json";
    Monster luke(Monster::parse(lukeFile));

    ASSERT_TRUE(luke.getDamage() > 0);
    ASSERT_TRUE(luke.getAttackCoolDown() > 0);
    ASSERT_TRUE(luke.getHealthPoints() > 0);

    std::string playerFile = "player.json";
    Monster player(Monster::parse(playerFile));

    ASSERT_TRUE(player.getDamage() > 0);
    ASSERT_TRUE(player.getAttackCoolDown() > 0);
    ASSERT_TRUE(player.getHealthPoints() > 0);
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
    EXPECT_NO_THROW(Game("map_1.txt"));
}

TEST(GameTest, MethodTestExpectNoThrow)
{
    Game g("map_1.txt");
    Map *m = new Map("map_2.txt");

    EXPECT_NO_THROW(g.SetMap(m));

    Hero *h = new Hero("Joe", 5, 5, 5.0, 5, 5, 5, 5.0);
    EXPECT_NO_THROW(g.PutHero(h, 1, 1));
}

TEST(GameTest, MethodTestExpectThrow)
{
    EXPECT_THROW({
        try
        {
            Game g;
            Hero *h = new Hero("Joe", 5, 5, 5.0, 5, 5, 5, 5.0);
            g.PutHero(h, 0, 0);
        }
        catch (const Map::WrongIndexException &e)
        {
            throw;
        } }, Map::WrongIndexException);

    EXPECT_THROW({
        try
        {
            Game g("map_1.txt");
            Hero *h = new Hero("Joe", 5, 5, 5.0, 5, 5, 5, 5.0);
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
            Game g("map_1.txt");
            Hero *h = new Hero("Joe", 5, 5, 5.0, 5, 5, 5, 5.0);
            g.PutHero(h, 0, 0);
        }
        catch (const Game::OccupiedException &e)
        {
            throw;
        } }, Game::OccupiedException);

    EXPECT_THROW({
        try
        {
            Game g("map_1.txt");
            Hero *h = new Hero("Joe", 5, 5, 5.0, 5, 5, 5, 5.0);
            g.PutHero(h, 1, 1);

            Map *m = new Map("map_2.txt");
            g.SetMap(m);
        }
        catch (const Game::AlreadyHasUnitsException &e)
        {
            throw;
        } }, Game::AlreadyHasUnitsException);

    EXPECT_THROW({
        try
        {
            Game g("map_1.txt");
            g.Run();
        }
        catch (const Game::NotInitializedException &e)
        {
            throw;
        } }, Game::NotInitializedException);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
