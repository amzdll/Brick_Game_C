#include "helpers.h"

bool is_collision(game_board_t game_board, block_t block) {
  if (block.height + block.y == HEIGHT) {
    return true;
  }

  for (size_t i = 0; i < block.height; ++i) {
    for (size_t j = 0; j < block.width; ++j) {
      if (block.field[i][j] && game_board.field[block.y + i + 1][block.x + j]) {
        // poka eto ponimau tolka ia i bog, zavtra budet znat' tolko bog.
        if ((i + 1 < block.height && !block.field[i + 1][j]) ||
            i + 1 == block.height) {
          return true;
        }
      }
    }
  }

  return false;
}

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

bool is_row_complete(int* row) {
  int key = 0;
  return !(int*)bsearch(&key, row, WIDTH, sizeof(int), compare);
}

bool is_game_over(game_board_t game_board, block_t block) {
  return is_collision(game_board, block) && block.y == 0;
}

// temp
void draw_field(game_board_t game_board) {
  printf(" \t");
  for (int i = 0; i < WIDTH; ++i) {
    printf("%d ", i);
  }
  printf(" \n");
  for (size_t i = 0; i < HEIGHT; ++i) {
    printf("%zu\t", i);
    for (size_t j = 0; j < WIDTH; ++j) {
      printf("%d ", game_board.field[i][j]);
    }
    printf("\n");
  }
}
