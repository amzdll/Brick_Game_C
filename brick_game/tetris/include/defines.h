#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_DEFINES_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_DEFINES_H_

// Tetris board
#define HEIGHT 20
#define WIDTH 10

// Tetris Block
#define BLOCKS_COUNT 7

#define I_BLOCK    \
  (int[1][4]) {    \
    { 1, 1, 1, 1 } \
  }

#define J_BLOCK            \
  (int[2][3]) {            \
    {1, 0, 0}, { 1, 1, 1 } \
  }

#define L_BLOCK            \
  (int[2][3]) {            \
    {0, 0, 1}, { 1, 1, 1 } \
  }

#define O_BLOCK      \
  (int[2][2]) {      \
    {1, 1}, { 1, 1 } \
  }

#define S_BLOCK            \
  (int[2][3]) {            \
    {0, 1, 1}, { 1, 1, 0 } \
  }

#define Z_BLOCK            \
  (int[2][3]) {            \
    {1, 1, 0}, { 0, 1, 1 } \
  }

#define T_BLOCK            \
  (int[2][3]) {            \
    {0, 1, 0}, { 1, 1, 1 } \
  }

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_DEFINES_H_
