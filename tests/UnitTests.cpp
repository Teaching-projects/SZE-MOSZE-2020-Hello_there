#include "gtest/gtest.h"
#include "../JSON.h"
#include "../Monster.h"
#include "../Hero.h"

TEST(ParserTest, CheckMapContent)
{
    std::ifstream vaderFile("units/vader.json");
    JSON vaderJSON = JSON::parseFromStream(vaderFile);
    EXPECT_EQ("Vader", vaderJSON.get<std::string>("name"));
    EXPECT_EQ(666, vaderJSON.get<int>("hp"));
    EXPECT_EQ(42, vaderJSON.get<int>("dmg"));
    EXPECT_EQ(6.9, vaderJSON.get<float>("attackcooldown"));

    std::ifstream lukeFile("units/luke.json");
    JSON lukeJSON = JSON::parseFromStream(lukeFile);
    EXPECT_EQ("Luke", lukeJSON.get<std::string>("name"));
    EXPECT_EQ(100, lukeJSON.get<int>("hp"));
    EXPECT_EQ(25, lukeJSON.get<int>("dmg"));
    EXPECT_EQ(3.0, lukeJSON.get<float>("attackcooldown"));

    std::ifstream palpatineFile("units/palpatine.json");
    JSON palpatineJSON = JSON::parseFromStream(palpatineFile);
    EXPECT_EQ("Palpatine", palpatineJSON.get<std::string>("name"));
    EXPECT_EQ(111, palpatineJSON.get<int>("hp"));
    EXPECT_EQ(21, palpatineJSON.get<int>("dmg"));
    EXPECT_EQ(2.5, palpatineJSON.get<float>("attackcooldown"));
}

TEST(ParserTest, ExpectExceptions)
{
    std::ifstream messyUnit("units/messy_unit.json");
    EXPECT_THROW(JSON::parseFromStream(messyUnit), const char *);

    const char *messyUnit2 = "units/messy_unit2.json";
    EXPECT_THROW(JSON::parseFromFile(messyUnit2), const char *);

	const char* messyUnit3 = "units/messy_unit3.json";
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
    std::string playerFile = "player.json";
    EXPECT_NO_THROW(Hero(Hero::parse(playerFile)));
}

TEST(UnitClassTest, NoCrazyValues)
{
    std::string vaderFile = "vader.json";
    Monster vader = Monster::parse(vaderFile);

    ASSERT_TRUE(vader.getDamage() > 0);
    ASSERT_TRUE(vader.getAttackCoolDown() > 0);
    ASSERT_TRUE(vader.getHealthPoints() > 0);

    std::string palpatineFile = "palpatine.json";
    Monster palpatine = Monster::parse(palpatineFile);

    ASSERT_TRUE(palpatine.getDamage() > 0);
    ASSERT_TRUE(palpatine.getAttackCoolDown() > 0);
    ASSERT_TRUE(palpatine.getHealthPoints() > 0);

    std::string lukeFile = "luke.json";
    Monster luke = Monster::parse(lukeFile);

    ASSERT_TRUE(luke.getDamage() > 0);
    ASSERT_TRUE(luke.getAttackCoolDown() > 0);
    ASSERT_TRUE(luke.getHealthPoints() > 0);

    std::string playerFile = "player.json";
    Monster player = Monster::parse(playerFile);

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
    EXPECT_TRUE(vaderJSON == vaderJSONLookalike);

    std::ifstream lukeFile("units/luke.json");
    JSON lukeJSON = JSON::parseFromStream(lukeFile);
    std::ifstream lukeFileLookalike("units/luke_lookalike.json");
    JSON lukeJSONLookalike = JSON::parseFromStream(lukeFileLookalike);
    EXPECT_TRUE(lukeJSON == lukeJSONLookalike);

    std::ifstream palpatineFile("units/palpatine.json");
    JSON palpatineJSON = JSON::parseFromStream(palpatineFile);
    std::ifstream palpatineFileLookalike("units/palpatine_lookalike.json");
    JSON palpatineJSONLookalike = JSON::parseFromStream(palpatineFileLookalike);
    EXPECT_TRUE(palpatineJSON == palpatineJSONLookalike);

    std::ifstream playerFile("units/player.json");
    JSON playerJSON = JSON::parseFromStream(playerFile);
    std::ifstream playerFileLookalike("units/player_lookalike.json");
    JSON playerJSONLookalike = JSON::parseFromStream(playerFileLookalike);
    EXPECT_TRUE(playerJSON == playerJSONLookalike);
}

TEST(ParserTest, IndifferentToKeyOrder)
{
    std::ifstream vaderFile("units/vader.json");
   JSON vaderJSON = JSON::parseFromStream(vaderFile);
    std::ifstream vaderFileLookalike("units/vader_lookalike2.json");
    JSON vaderJSONLookalike = JSON::parseFromStream(vaderFileLookalike);
	EXPECT_TRUE(vaderJSON == vaderJSONLookalike);

    std::ifstream lukeFile("units/luke.json");
    JSON lukeJSON = JSON::parseFromStream(lukeFile);
    std::ifstream lukeFileLookalike("units/luke_lookalike2.json");
    JSON lukeJSONLookalike = JSON::parseFromStream(lukeFileLookalike);
	EXPECT_TRUE(lukeJSON == lukeJSONLookalike);

    std::ifstream palpatineFile("units/palpatine.json");
    JSON palpatineJSON = JSON::parseFromStream(palpatineFile);
    std::ifstream palpatineFileLookalike("units/palpatine_lookalike2.json");
    JSON palpatineJSONLookalike = JSON::parseFromStream(palpatineFileLookalike);
	EXPECT_TRUE(palpatineJSON == palpatineJSONLookalike);

    std::ifstream playerFile("units/player.json");
    JSON playerJSON = JSON::parseFromStream(playerFile);
    std::ifstream playerFileLookalike("units/player_lookalike2.json");
    JSON playerJSONLookalike = JSON::parseFromStream(playerFileLookalike);
	EXPECT_TRUE(playerJSON == playerJSONLookalike);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
