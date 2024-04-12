#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_MEMORY_MANAGEMENT_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_MEMORY_MANAGEMENT_H_

#include <stdbool.h>
#include <stdlib.h>

int** allocate_int_two_dimensional_array(size_t height, size_t width);
void free_int_two_dimensional_array(size_t height, size_t width, int**two_dimensional_array);

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_MEMORY_MANAGEMENT_H_
