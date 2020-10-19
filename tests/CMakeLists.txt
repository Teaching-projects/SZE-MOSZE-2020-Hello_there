cmake_minimum_required(VERSION 3.17)
project(hello_there_gtests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(UnitTests UnitTests.cpp ../JsonParser.cpp)
target_link_libraries(UnitTests ${GTEST_LIBRARIES} pthread)