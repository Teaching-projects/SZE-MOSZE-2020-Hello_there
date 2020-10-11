#include "gtest/gtest.h"
#include "JsonParser.h"

TEST(ParserTest, CheckReturnedMapSize)
{
    EXPECT_EQ(3, JsonParser::Parse("vader.json").size());
    EXPECT_EQ(3, JsonParser::Parse("luke.json").size());
    EXPECT_EQ(3, JsonParser::Parse("palpatine.json").size());
}
