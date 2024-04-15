#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_

#include "game_entities.h"

block_t create_block(block_t* blocks);

void place_block(game_board_t* game_board, block_t block);
void remove_block(game_board_t* game_board, block_t block);

void turn_block(game_board_t* game_board, block_t block);
void left_shift(game_board_t* game_board, block_t* block);
void right_shift(game_board_t* game_board, block_t* block);
void down_move(game_board_t* game_board, block_t* block);

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_
