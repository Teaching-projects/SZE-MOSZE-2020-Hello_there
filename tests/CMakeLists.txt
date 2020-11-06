cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_library(parserSrc ../JsonParser.cpp)
add_library(unitSrc ../Unit.cpp)
add_library(playerSrc ../Player.cpp)
add_executable(unit_tests UnitTests.cpp)

target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread parserSrc unitSrc playerSrc)