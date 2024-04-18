#ifndef TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_
#define TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_

#include <stdbool.h>
#include "ncurses.h"
#include "game_entities.h"

bool is_collision(game_board_t game_board, block_t block);
bool is_game_over(game_board_t game_board, block_t block);
bool is_row_complete(const int* row);

void clear_game_board(game_board_t game_board);

int compare_nums(const void* a, const void* b);

void shift_block_cells(block_t* block);

void draw_field(game_board_t game_board);
#endif  // TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_
