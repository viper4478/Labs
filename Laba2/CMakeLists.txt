cmake_minimum_required(VERSION 3.6)
project(Laba2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -pedantic")

set(SOURCE_FILES lab2.c)
add_executable(Laba2 ${SOURCE_FILES})

target_link_libraries(Laba2 m)