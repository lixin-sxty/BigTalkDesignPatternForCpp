cmake_minimum_required(VERSION 3.5)

project(proxy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall")

file(GLOB SRCS *.cpp)

add_executable(ch7 ${SRCS})

target_include_directories(ch7 PRIVATE ${PROJECT_SOURCE_DIR})
