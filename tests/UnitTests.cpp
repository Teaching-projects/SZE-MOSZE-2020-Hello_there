#include "gtest/gtest.h"
#include "../JsonParser.h"

TEST(ParserTest, CheckReturnedMapSize)
{
    std::ifstream f1("../units/vader.json");
    EXPECT_EQ(3, JsonParser::Parse(f1).size());

    std::ifstream f2("../units/luke.json");
    EXPECT_EQ(3, JsonParser::Parse(f2).size());

    std::ifstream f3("../units/palpatine.json");
    EXPECT_EQ(3, JsonParser::Parse(f3).size());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
