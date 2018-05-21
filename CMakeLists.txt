cmake_minimum_required(VERSION 3.10)
project(TicTacToe C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(TicTacToe main.c)
target_link_libraries(TicTacToe ${SDL2_LIBRARIES})