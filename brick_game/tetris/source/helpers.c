#include "helpers.h"

bool is_collision(game_board_t game_board, block_t block) {
  if (block.height + block.y == HEIGHT) {
    return true;
  }
  for (int i = 1; i < block.height; ++i) {
    for (int j = 0; j < block.width; ++j) {
      if (game_board.field[block.y + i][block.x + j] &&
          game_board.field[block.y + i + 1][block.x + j]) {
        return true;
      }
    }
  }
  return false;
}

bool is_game_over(game_board_t game_board, block_t block) {
  return is_collision(game_board, block) && block.y == 0;
}
