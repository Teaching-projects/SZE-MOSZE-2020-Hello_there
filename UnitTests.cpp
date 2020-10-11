#include "UnitTests.h"
#include "gtest/gtest.h"
#include "JsonParser.h"

TEST(ParserTest, CheckReturnedMapSize)
{
    EXPECT_EQ(3, JsonParser::Parse("vader.json").size());
    EXPECT_EQ(3, JsonParser::Parse("luke.json").size());
    EXPECT_EQ(3, JsonParser::Parse("palpatine.json").size());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
