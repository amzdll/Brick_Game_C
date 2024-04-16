#ifndef TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_
#define TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_

#include <stdbool.h>

#include "game_entities.h"

bool is_collision(game_board_t game_board, block_t block);
bool is_game_over(game_board_t game_board, block_t block);
bool is_row_complete(int* row);
int compare_nums(const void* a, const void* b);



void init_random_seed();


void draw_field(game_board_t game_board);
#endif  // TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_
