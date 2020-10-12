cmake_minimum_required(VERSION 3.17)
project(hello_there_gtests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

get_filename_component(PARENT_DIR ../ ABSOLUTE)
include_directories(${PARENT_DIR})

add_executable(UnitTests UnitTests.cpp ${PARENT_DIR}/JsonParser.cpp)
target_compile_features(UnitTests PRIVATE cxx_std_17)
target_link_libraries(UnitTests ${GTEST_LIBRARIES} pthread)