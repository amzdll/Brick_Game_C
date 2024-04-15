cmake_minimum_required(VERSION 3.26)
project(TETRIS_LIB LANGUAGES C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES source/*.c)
file(GLOB_RECURSE HEADERS include/*.h)

include_directories(source include)


add_library(TetrisLib STATIC
        ${HEADERS}
        ${SOURCES}
)

target_include_directories(TetrisLib PUBLIC include)