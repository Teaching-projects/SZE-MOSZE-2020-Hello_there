cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set (CMAKE_CXX_STANDARD 17)

add_library(parserSrc ../JSON.cpp)
add_library(monsterSrc ../Monster.cpp)
add_library(heroSrc ../Hero.cpp)
add_executable(unit_tests UnitTests.cpp)

target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread parserSrc monsterSrc heroSrc)
target_compile_features(unit_tests PRIVATE cxx_std_17)