#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_

#include <string.h>

#include "game_entities.h"

// block creation / remove logic
block_t create_block(block_t* blocks);

void place_block(game_board_t* game_board, block_t block);
void remove_block(game_board_t* game_board, block_t block);

// block movement logic
void turn_block(game_board_t* game_board, block_t block);
void move_left(game_board_t* game_board, block_t* block);
void move_right(game_board_t* game_board, block_t* block);
void move_down(game_board_t* game_board, block_t* block);

// game board logic
void game_board_shift(game_board_t* game_board, int row_index);

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_
