cmake_minimum_required(VERSION 3.26)
project(TETRIS_LIB LANGUAGES C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES source/*.c)
file(GLOB_RECURSE HEADERS include/*.h)

set(tetris_lib
        ${HEADERS}
        ${SOURCES})

ADD_EXECUTABLE(tetris ${tetris_lib})
target_include_directories(tetris PUBLIC include)
cmake_minimum_required(VERSION 3.26)
