cmake_minimum_required(VERSION 3.5)

project(facade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall")

file(GLOB SRCS *.cpp)

add_executable(ch12 ${SRCS})

target_include_directories(ch12 PRIVATE ${PROJECT_SOURCE_DIR})
