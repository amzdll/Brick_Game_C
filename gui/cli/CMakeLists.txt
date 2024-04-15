cmake_minimum_required(VERSION 3.26)
project(TetrisCli)
set(CMAKE_C_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES ./*.c)
file(GLOB_RECURSE HEADERS ./*.h)

ADD_EXECUTABLE(CLI
        ${SOURCES}
        ${HEADERS}
)

target_link_libraries(CLI PRIVATE TetrisLib)