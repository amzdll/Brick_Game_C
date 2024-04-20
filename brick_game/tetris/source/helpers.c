#include "helpers.h"

#include <string.h>

bool IsCollision(GameBoard game_board, Block block) {
  bool collision = false;
  if (block.height + block.y == HEIGHT) {
    collision = true;
  }
  for (size_t i = 0; i < block.height && !collision; ++i) {
    for (size_t j = 0; j < block.width && !collision; ++j) {
      if (block.field[i][j] && game_board[block.y + i + 1][block.x + j] &&
          ((i + 1 < block.height && !block.field[i + 1][j]) ||
           i + 1 == block.height)) {
        collision = true;
      }
    }
  }
  return collision;
}

bool IsRowComplete(const int* row) {
  for (int i = 0; i < WIDTH; ++i) {
    if (row[i] == 0) {
      return false;
    }
  }
  return true;
}

bool IsGameOver(GameBoard game_board, Block block) {
  return IsCollision(game_board, block) && block.y == 0;
}

void ClearGameBoard(GameBoard game_board) {
  for (int i = 0; i < HEIGHT; ++i) {
    memset(game_board[i], 0, WIDTH * sizeof(int));
  }
}

void ShiftBlockCells(Block* block) {
  size_t left_cell_index = block->width;
  for (size_t i = 0; i < block->field_dimension; i++) {
    for (size_t j = 0; j < block->field_dimension; j++) {
      if (block->field[i][j] != 0) {
        left_cell_index = left_cell_index < j ? left_cell_index : j;
        break;
      }
    }
  }
  for (size_t i = 0; i < block->field_dimension; ++i) {
    for (size_t j = left_cell_index; j < block->width; ++j) {
      block->field[i][j - left_cell_index] = block->field[i][j];
    }
  }
  for (size_t i = 0; i < block->field_dimension; ++i) {
    for (size_t j = block->field_dimension - left_cell_index;
         j < block->field_dimension; ++j) {
      block->field[i][j] = 0;
    }
  }
}

// temp
void draw_field(GameBoard game_board) {
  printf(" \t");
  for (int i = 0; i < 10; ++i) {
    printf("%d ", i);
  }
  printf(" \n");
  for (size_t i = 0; i < 20; ++i) {
    printf("%zu\t", i);
    for (size_t j = 0; j < 10; ++j) {
      printf("%c", game_board[i][j] ? '#' : '-');
    }
    printf("\n");
  }
}
