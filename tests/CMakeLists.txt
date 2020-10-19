cmake_minimum_required(VERSION 2.6)
project(hello_there_gtests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(parserSrc ../JsonParser.cpp)
add_executable(unit_tests UnitTests.cpp)

target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread parserSrc)