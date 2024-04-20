#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_MEMORY_MANAGEMENT_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_MEMORY_MANAGEMENT_H_

#include <stdbool.h>
#include <stdlib.h>

#include "game_entities.h"

int** AllocateIntTwoDimensionalArray(size_t height, size_t width);
void FreeIntTwoDimensionalArray(int** two_dimensional_array, size_t height);
// void free_blocks(block_t* blocks);
#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_MEMORY_MANAGEMENT_H_
