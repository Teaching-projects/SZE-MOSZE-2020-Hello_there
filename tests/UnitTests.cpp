#include "gtest/gtest.h"
#include "../JSON.h"
#include "../Monster.h"
#include "../Hero.h"

TEST(ParserTest, CheckMapContent)
{
    std::ifstream vaderFile("units/vader.json");
    std::map<std::string, std::string> vaderMap = JSON::Parse(vaderFile);
    EXPECT_EQ("Vader", vaderMap["name"]);
    EXPECT_EQ("666", vaderMap["hp"]);
    EXPECT_EQ("42", vaderMap["dmg"]);
    EXPECT_EQ("6.9", vaderMap["attackcooldown"]);

    std::ifstream lukeFile("units/luke.json");
    std::map<std::string, std::string> lukeMap = JSON::Parse(lukeFile);
    EXPECT_EQ("Luke", lukeMap["name"]);
    EXPECT_EQ("100", lukeMap["hp"]);
    EXPECT_EQ("25", lukeMap["dmg"]);
    EXPECT_EQ("3.0", lukeMap["attackcooldown"]);

    std::ifstream palpatineFile("units/palpatine.json");
    std::map<std::string, std::string> palpatineMap = JSON::Parse(palpatineFile);
    EXPECT_EQ("Palpatine", palpatineMap["name"]);
    EXPECT_EQ("111", palpatineMap["hp"]);
    EXPECT_EQ("21", palpatineMap["dmg"]);
    EXPECT_EQ("2.5", palpatineMap["attackcooldown"]);
}

TEST(ParserTest, ExpectExceptions)
{
    std::ifstream messyUnit("units/messy_unit.json");
    EXPECT_THROW(JSON::Parse(messyUnit), const char *);

    const char *messyUnit2 = "messy_unit2.json";
    EXPECT_THROW(JSON::Parse(messyUnit2), const char *);

    std::string messyUnit3 = "messy_unit3.json";
    EXPECT_THROW(JSON::Parse(messyUnit3), const char *);
}

TEST(ParserTest, ExpectNoExceptions)
{
    std::ifstream vaderFile("units/vader.json");
    EXPECT_NO_THROW(JSON::Parse(vaderFile));

    const char *lukeFile = "luke.json";
    EXPECT_NO_THROW(JSON::Parse(lukeFile));

    std::string palpatineFile = "palpatine.json";
    EXPECT_NO_THROW(JSON::Parse(palpatineFile));
}

TEST(UnitClassTest, SuccessfulConstruction)
{
    EXPECT_NO_THROW(std::string("vader.json"));

    EXPECT_NO_THROW(std::string("palpatine.json"));

    EXPECT_NO_THROW(std::string("luke.json"));
}

TEST(PlayerClassTest, SuccessfulConstruction)
{
    std::string playerFile = "player.json";
    EXPECT_NO_THROW(Player(Unit::ParseUnit(playerFile)));
}

TEST(UnitClassTest, NoCrazyValues)
{
    std::string vaderFile = "vader.json";
    Unit vader = Unit::ParseUnit(vaderFile);

    ASSERT_TRUE(vader.GetDmg() > 0);
    ASSERT_TRUE(vader.GetAtkCoolDown() > 0);
    ASSERT_TRUE(vader.GetHp() > 0);

    std::string palpatineFile = "palpatine.json";
    Unit palpatine = Unit::ParseUnit(palpatineFile);

    ASSERT_TRUE(palpatine.GetDmg() > 0);
    ASSERT_TRUE(palpatine.GetAtkCoolDown() > 0);
    ASSERT_TRUE(palpatine.GetHp() > 0);

    std::string lukeFile = "luke.json";
    Unit luke = Unit::ParseUnit(lukeFile);

    ASSERT_TRUE(luke.GetDmg() > 0);
    ASSERT_TRUE(luke.GetAtkCoolDown() > 0);
    ASSERT_TRUE(luke.GetHp() > 0);

    std::string playerFile = "player.json";
    Unit player = Unit::ParseUnit(playerFile);

    ASSERT_TRUE(player.GetDmg() > 0);
    ASSERT_TRUE(player.GetAtkCoolDown() > 0);
    ASSERT_TRUE(player.GetHp() > 0);
}

TEST(ParserTest, IndifferentToSpaces)
{
    std::ifstream vaderFile("units/vader.json");
    std::map<std::string, std::string> vaderMap = JSON::Parse(vaderFile);
    std::ifstream vaderFileLookalike("units/vader_lookalike.json");
    std::map<std::string, std::string> vaderMapLookalike = JSON::Parse(vaderFileLookalike);
    EXPECT_TRUE(vaderMap == vaderMapLookalike);

    std::ifstream lukeFile("units/luke.json");
    std::map<std::string, std::string> lukeMap = JSON::Parse(lukeFile);
    std::ifstream lukeFileLookalike("units/luke_lookalike.json");
    std::map<std::string, std::string> lukeMapLookalike = JSON::Parse(lukeFileLookalike);
    EXPECT_TRUE(lukeMap == lukeMapLookalike);

    std::ifstream palpatineFile("units/palpatine.json");
    std::map<std::string, std::string> palpatineMap = JSON::Parse(palpatineFile);
    std::ifstream palpatineFileLookalike("units/palpatine_lookalike.json");
    std::map<std::string, std::string> palpatineMapLookalike = JSON::Parse(palpatineFileLookalike);
    EXPECT_TRUE(palpatineMap == palpatineMapLookalike);

    std::ifstream playerFile("units/player.json");
    std::map<std::string, std::string> playerMap = JSON::Parse(playerFile);
    std::ifstream playerFileLookalike("units/player_lookalike.json");
    std::map<std::string, std::string> playerMapLookalike = JSON::Parse(playerFileLookalike);
    EXPECT_TRUE(playerMap == playerMapLookalike);
}

TEST(ParserTest, IndifferentToKeyOrder)
{
    std::ifstream vaderFile("units/vader.json");
    std::map<std::string, std::string> vaderMap = JSON::Parse(vaderFile);
    std::ifstream vaderFileLookalike("units/vader_lookalike2.json");
    std::map<std::string, std::string> vaderMapLookalike = JSON::Parse(vaderFileLookalike);
    EXPECT_TRUE(JSON::CompareMaps(vaderMap, vaderMapLookalike));

    std::ifstream lukeFile("units/luke.json");
    std::map<std::string, std::string> lukeMap = JSON::Parse(lukeFile);
    std::ifstream lukeFileLookalike("units/luke_lookalike2.json");
    std::map<std::string, std::string> lukeMapLookalike = JSON::Parse(lukeFileLookalike);
    EXPECT_TRUE(JSON::CompareMaps(lukeMap, lukeMapLookalike));

    std::ifstream palpatineFile("units/palpatine.json");
    std::map<std::string, std::string> palpatineMap = JSON::Parse(palpatineFile);
    std::ifstream palpatineFileLookalike("units/palpatine_lookalike2.json");
    std::map<std::string, std::string> palpatineMapLookalike = JSON::Parse(palpatineFileLookalike);
    EXPECT_TRUE(JSON::CompareMaps(palpatineMap, palpatineMapLookalike));

    std::ifstream playerFile("units/player.json");
    std::map<std::string, std::string> playerMap = JSON::Parse(playerFile);
    std::ifstream playerFileLookalike("units/player_lookalike2.json");
    std::map<std::string, std::string> playerMapLookalike = JSON::Parse(playerFileLookalike);
    EXPECT_TRUE(JSON::CompareMaps(playerMap, playerMapLookalike));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}