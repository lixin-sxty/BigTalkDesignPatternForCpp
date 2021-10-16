cmake_minimum_required(VERSION 3.5)

project(builder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall")

file(GLOB SRCS *.cpp)

add_executable(ch13 ${SRCS})

target_include_directories(ch13 PRIVATE ${PROJECT_SOURCE_DIR})
