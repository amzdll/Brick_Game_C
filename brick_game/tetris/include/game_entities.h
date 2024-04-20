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

typedef int** GameBoard;

typedef struct {
  size_t x;
  size_t y;
  size_t height;
  size_t width;
  size_t field_dimension;
  int** field;
} Block;

typedef struct {
  GameBoard game_board;
  Block current_block;
  Block* block_pool;
} GameInstance;

typedef struct {
  int score;
  int level;
  int speed;
  game_state current_state;
} GameParameters;

GameInstance InitializeGameInstance();
GameParameters InitializeGameParameters();

Block* InitializeBlocks();
Block InitializeBlock(size_t height, size_t width, int (*figure)[width]);
Block CreateBlock(Block* blocks);

void InitializeRandomSeed();

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_GAME_ENTITIES_H_
