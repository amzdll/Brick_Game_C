#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_GAME_ENTITIES_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_GAME_ENTITIES_H_

#include <stdio.h>
#include <stdlib.h>

#include "defines.h"
#include "memory_management.h"

typedef int** game_board_t;

typedef struct block {
  size_t x;
  size_t y;
  size_t height;
  size_t width;
  int** field;
} block_t;

typedef struct game_stats {
  int score;
  int level;
  int speed;
  bool lives;
  bool won;
} game_stats_t;


game_board_t initialize_game_board();
block_t* initialize_blocks();
block_t initialize_block(size_t height, size_t width, int (*figure)[width]);

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_GAME_ENTITIES_H_
