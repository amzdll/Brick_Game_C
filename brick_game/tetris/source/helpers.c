#include "helpers.h"

#include <string.h>

bool is_collision(game_board_t game_board, block_t block) {
  bool collision = false;

  if (block.height + block.y == HEIGHT) {
    collision = true;
  }

  for (size_t i = 0; i < block.height && !collision; ++i) {
    for (size_t j = 0; j < block.width && !collision; ++j) {
      // poka eto ponimau tolka ia i bog, zavtra budet znat' tolko bog.
      if (block.field[i][j] && game_board[block.y + i + 1][block.x + j] &&
          ((i + 1 < block.height && !block.field[i + 1][j]) ||
           i + 1 == block.height)) {
        collision = true;
      }
    }
  }
  return collision;
}

bool is_row_complete(const int* row) {
  for (int i = 0; i < WIDTH; ++i) {
    if (row[i] == 0) {
      return false;
    }
  }
  return true;

  //  return !(int*)bsearch((void*)&(int){0}, row, WIDTH, sizeof(int),
  //                        compare_nums);
}

bool is_game_over(game_board_t game_board, block_t block) {
  return is_collision(game_board, block) && block.y == 0;
}

void clear_game_board(game_board_t game_board) {
  for (int i = 0; i < HEIGHT; ++i) {
    memset(game_board[i], 0, WIDTH * sizeof(int));
  }
}

void shift_block_cells(block_t* block) {
  size_t left_cell_index = block->width;
  for (size_t i = 0; i < block->field_dimenssion; i++) {
    for (size_t j = 0; j < block->field_dimenssion; j++) {
      if (block->field[i][j] != 0) {
        left_cell_index = left_cell_index < j ? left_cell_index : j;
        break;
      }
    }
  }
  for (size_t i = 0; i < block->field_dimenssion; ++i) {
    for (size_t j = left_cell_index; j < block->width; ++j) {
      block->field[i][j - left_cell_index] = block->field[i][j];
    }
  }
  for (size_t i = 0; i < block->field_dimenssion; ++i) {
    for (size_t j = block->field_dimenssion - left_cell_index;
         j < block->field_dimenssion; ++j) {
      block->field[i][j] = 0;
    }
  }
}

// temp
void draw_field(game_board_t game_board) {
  printf(" \t");
  for (int i = 0; i < 3; ++i) {
    printf("%d ", i);
  }
  printf(" \n");
  for (size_t i = 0; i < 3; ++i) {
    printf("%zu\t", i);
    for (size_t j = 0; j < 3; ++j) {
      printf("%d ", game_board[i][j]);
    }
    printf("\n");
  }
}
