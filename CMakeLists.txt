cmake_minimum_required(VERSION 3.10)
project(TicTacToe C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH /usr/share/cmake-3.5/Modules)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIRS})

add_executable(TicTacToe main.c)
target_link_libraries(TicTacToe ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARY})