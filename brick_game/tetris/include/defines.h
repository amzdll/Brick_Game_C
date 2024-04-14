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
    {2, 0, 0}, { 2, 2, 2 } \
  }

#define L_BLOCK            \
  (int[2][3]) {            \
    {0, 0, 3}, { 3, 3, 3 } \
  }

#define O_BLOCK      \
  (int[2][2]) {      \
    {4, 4}, { 4, 4 } \
  }

#define S_BLOCK            \
  (int[2][3]) {            \
    {0, 5, 5}, { 5, 5, 0 } \
  }

#define Z_BLOCK            \
  (int[2][3]) {            \
    {6, 6, 0}, { 0, 6, 6 } \
  }

#define T_BLOCK            \
  (int[2][3]) {            \
    {0, 7, 0}, { 7, 7, 7 } \
  }

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_DEFINES_H_
