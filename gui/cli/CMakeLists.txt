cmake_minimum_required(VERSION 3.26)
project(TetrisCli)
set(CMAKE_C_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES ./*.c)
file(GLOB_RECURSE HEADERS ./*.h)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(CLI
        ${SOURCES}
        ${HEADERS}
)

target_link_libraries(CLI PRIVATE TetrisLib ${CURSES_LIBRARIES} form)