#include "gtest/gtest.h"
#include "../JsonParser.h"

TEST(ParserTest, CheckMapContent)
{
    std::ifstream vaderFile("units/vader.json");
    std::map<std::string, std::string> vaderMap = JsonParser::Parse(vaderFile);
    EXPECT_EQ("Vader", vaderMap["name"]);
    EXPECT_EQ("666", vaderMap["hp"]);
    EXPECT_EQ("42", vaderMap["dmg"]);
    EXPECT_EQ("6.9", vaderMap["attackcooldown"]);

    std::ifstream lukeFile("units/luke.json");
    std::map<std::string, std::string> lukeMap = JsonParser::Parse(lukeFile);
    EXPECT_EQ("Luke", lukeMap["name"]);
    EXPECT_EQ("100", lukeMap["hp"]);
    EXPECT_EQ("25", lukeMap["dmg"]);
    EXPECT_EQ("3.0", lukeMap["attackcooldown"]);

    std::ifstream palpatineFile("units/palpatine.json");
    std::map<std::string, std::string> palpatineMap = JsonParser::Parse(palpatineFile);
    EXPECT_EQ("Palpatine", palpatineMap["name"]);
    EXPECT_EQ("111", palpatineMap["hp"]);
    EXPECT_EQ("21", palpatineMap["dmg"]);
    EXPECT_EQ("2.5", palpatineMap["attackcooldown"]);
}

TEST(ParserTest, ExpectExceptions)
{
    std::ifstream messyUnit("units/messy_unit.json");
    EXPECT_THROW(JsonParser::Parse(messyUnit), const char *);

    const char *messyUnit2 = "messy_unit2.json";
    EXPECT_THROW(JsonParser::Parse(messyUnit2), const char *);

    std::string messyUnit3 = "messy_unit3.json";
    EXPECT_THROW(JsonParser::Parse(messyUnit3), const char *);
}

TEST(ParserTest, ExpectNoExceptions)
{
    std::ifstream vaderFile("units/vader.json");
    EXPECT_NO_THROW(JsonParser::Parse(vaderFile));

    const char *lukeFile = "luke.json";
    EXPECT_NO_THROW(JsonParser::Parse(lukeFile));

    std::string palpatineFile = "palpatine.json";
    EXPECT_NO_THROW(JsonParser::Parse(palpatineFile));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
