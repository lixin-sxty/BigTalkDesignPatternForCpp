cmake_minimum_required(VERSION 3.5)

project(abstract_factory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall")

file(GLOB SRCS *.cpp)

add_executable(ch15 ${SRCS})

target_include_directories(ch15 PRIVATE ${PROJECT_SOURCE_DIR})
