#include "services.h"

#include <string.h>

void place_block(game_board_t* game_board, block_t block) {
  for (int i = 0; i < block.height; ++i) {
    for (int j = 0; j < block.width; ++j) {
      game_board->field[block.y + i][block.x + j] |= block.field[i][j];
    }
  }
}

void remove_block(game_board_t* game_board, block_t block) {
  // fix
  for (int i = 0; i < block.height; ++i) {
    for (int j = 0; j < block.width; ++j) {
      /*
       * 0 0
       * 0 1
       * 1 0
       * 1 1
       *
       *  (a & b) * !b
      */
      game_board->field[block.y + i][block.x + j] =
          (game_board->field[block.y + i][block.x + j] & block.field[i][j])
              ? 0
              : game_board->field[block.y + i][block.x + j];
    }
  }
}

void turn_block(game_board_t* game_board, block_t block) {
  // todo: statement guard

  remove_block(game_board, block);
  int block_cell = 0;
  for (int i = 0; i < block.height / 2; i++) {
    for (int j = i; j < block.width - i - 1; j++) {
      block_cell = block.field[i][j];
      block.field[i][j] = block.field[block.height - 1 - j][i];
      block.field[block.height - 1 - j][i] =
          block.field[block.height - 1 - i][block.width - 1 - j];
      block.field[block.height - 1 - i][block.width - 1 - j] =
          block.field[j][block.width - 1 - i];
      block.field[j][block.width - 1 - i] = block_cell;
    }
  }
  place_block(game_board, block);
}

void left_shift(game_board_t* game_board, block_t block) {
  if (block.x == 0) {
    return;
  }
  remove_block(game_board, block);
  block.x -= 1;
  place_block(game_board, block);
}

void right_shift(game_board_t* game_board, block_t block) {
  if (block.x + block.width == game_board->width) {
    return;
  }
  remove_block(game_board, block);
  block.x += 1;
  place_block(game_board, block);
}

void down_move(game_board_t* game_board, block_t block) {}
