#include "services.h"

#include "helpers.h"

block_t create_block(block_t* blocks) {
#ifdef __APPLE__
  uint32_t block_index = arc4random() % BLOCKS_COUNT;
#else
  int block_index = rand() % 7;
#endif
  block_t block = blocks[block_index];
  //  block.x = (int)(WIDTH - block.width) / 2;
  //  block.y = 0;
  return block;
}

void place_block(game_board_t game_board, block_t block) {
  for (int i = 0; i < block.height; ++i) {
    for (int j = 0; j < block.width; ++j) {
      game_board[block.y + i][block.x + j] |= block.field[i][j];
    }
  }
}

void remove_block(game_board_t game_board, block_t block) {
  int* game_board_cell = NULL;
  int* block_cell = NULL;
  for (int i = 0; i < block.height; ++i) {
    for (int j = 0; j < block.width; ++j) {
      game_board_cell = &game_board[block.y + i][block.x + j];
      block_cell = &block.field[i][j];
      *game_board_cell = (*game_board_cell ^ *block_cell) * !*block_cell;
    }
  }
}

void spawn_block(game_board_t game_board, block_t block) {
  place_block(game_board, block);
}

void rotate_block(game_board_t game_board, block_t* block) {
  // todo: statement guard


  remove_block(game_board, *block);
  int block_cell = 0;
  for (int i = 0; i < block->field_dimenssion / 2; i++) {
    for (int j = i; j < block->field_dimenssion - i - 1; j++) {
      block_cell = block->field[i][j];
      block->field[i][j] = block->field[block->field_dimenssion - 1 - j][i];
      block->field[block->field_dimenssion - 1 - j][i] =
          block->field[block->field_dimenssion - 1 - i]
                      [block->field_dimenssion - 1 - j];
      block->field[block->field_dimenssion - 1 - i]
                  [block->field_dimenssion - 1 - j] =
          block->field[j][block->field_dimenssion - 1 - i];
      block->field[j][block->field_dimenssion - 1 - i] = block_cell;
    }
  }
  shift_block_cells(block);
  size_t block_width = block->height;
  size_t block_height = block->width;

  block->width = block_width;
  block->height = block_height;

  place_block(game_board, *block);
}

void move_left(game_board_t game_board, block_t* block) {
  if (block->x == 0) {
    return;
  }
  remove_block(game_board, *block);
  --block->x;
  place_block(game_board, *block);
}

void move_right(game_board_t game_board, block_t* block) {
  // statement guard
  // for height for  last_elemnt width && last_elemnt width + 1 || ...
  if (block->x + block->width == WIDTH) {
    return;
  }
  // FIX
  for (int i = 0; i < block->height; ++i) {
    if (game_board[block->y][block->x + block->width]) {
      return;
    }
  }

  remove_block(game_board, *block);
  ++block->x;
  place_block(game_board, *block);
}

void move_down(game_board_t game_board, block_t* block) {
  remove_block(game_board, *block);
  ++block->y;
  place_block(game_board, *block);
}

void game_board_shift(game_board_t game_board, int row_index) {
  memset(game_board[row_index], 0, WIDTH * sizeof(int));
  for (int i = row_index - 1; i > 0; --i) {
    memcpy(game_board[i + 1], game_board[i], WIDTH * sizeof(int));
  }
}

//  void fast_down_move() {}