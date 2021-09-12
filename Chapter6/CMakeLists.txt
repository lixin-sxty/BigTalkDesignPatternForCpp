cmake_minimum_required(VERSION 3.5)

project(decorator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall")

file(GLOB SRCS *.cpp)

add_executable(ch6 ${SRCS})

target_include_directories(ch6 PRIVATE ${PROJECT_SOURCE_DIR})
