#include "helpers.h"

bool is_collision(game_board_t game_board, block_t block) {
  if (block.height + block.y == HEIGHT) {
    printf("hui\n");
    return true;
  }
  for (int i = 0; i < block.height; ++i) {
    for (int j = 0; j < block.width; ++j) {
      if (block.field[i][j] && !block.field[i + 1][j]
          //          !block[i][j] &&/
          //          game_board.field[block.y + i][block.x + j] &&
          //          game_board.field[block.y + i + 1][block.x + j]
      ) {
        return true;
      }
    }
  }

  return false;
}

bool is_game_over(game_board_t game_board, block_t block) {
  return is_collision(game_board, block) && block.y == 0;
}

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

bool is_row_complete(int* row) {
  int key = 0;
  return !(int*)bsearch(&key, row, WIDTH, sizeof(int), compare);
}
