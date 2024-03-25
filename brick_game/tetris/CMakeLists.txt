cmake_minimum_required(VERSION 3.26)
project(TETRIS_LIB LANGUAGES C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES source/*.c)
file(GLOB_RECURSE HEADERS include/*.h)


set(tetris_lib
        ${HEADERS}
        ${SOURCES}
        include/game_entities.h
        include/memory_management.h
        source/memory_management.c
        include/services.h
        source/services.c
        include/fsm.h
)

ADD_EXECUTABLE(ttetris_lib ${tetris_lib})

target_include_directories(ttetris_lib PUBLIC include)
