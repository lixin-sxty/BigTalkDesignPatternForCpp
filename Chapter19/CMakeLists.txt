cmake_minimum_required(VERSION 3.5)

project(composite)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall")

file(GLOB SRCS *.cpp)

add_executable(ch19 ${SRCS})

target_include_directories(ch19 PRIVATE ${PROJECT_SOURCE_DIR})
