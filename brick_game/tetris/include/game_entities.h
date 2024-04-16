#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_GAME_ENTITIES_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_GAME_ENTITIES_H_

#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zconf.h>

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

typedef struct game_instance {
  game_board_t game_board;
  block_t current_block;
  block_t* block_pool;
} game_instance_t;

typedef struct game_parameters {
  int score;
  int level;
  int speed;
  game_state current_state;
} game_parameters_t;

game_instance_t initialize_game_instance();
game_parameters_t initialize_game_parameters();
block_t* initialize_blocks();
block_t initialize_block(size_t height, size_t width, int (*figure)[width]);
void initialize_random_seed();

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_GAME_ENTITIES_H_
