#include "game_entities.h"

#include <memory.h>

game_board_t initialize_game_board() {
  game_board_t game_board = {
      HEIGHT, WIDTH,
      allocate_int_two_dimensional_array((size_t)HEIGHT, (size_t)WIDTH)};
  return game_board;
}

block_t *initialize_blocks() {
  block_t *blocks = (block_t *)calloc(BLOCKS_COUNT, sizeof(block_t));

  blocks[0] = initialize_block(1, 4, I_BLOCK);
  blocks[1] = initialize_block(2, 3, J_BLOCK);
  blocks[2] = initialize_block(2, 3, L_BLOCK);
  blocks[3] = initialize_block(2, 2, O_BLOCK);
  blocks[4] = initialize_block(2, 3, S_BLOCK);
  blocks[5] = initialize_block(2, 3, Z_BLOCK);
  blocks[6] = initialize_block(2, 3, T_BLOCK);

  return blocks;
}

block_t initialize_block(size_t height, size_t width, int (*figure)[width]) {
  size_t dimension = height > width ? height : width;
  block_t block = {0, 0, height, width,
                   allocate_int_two_dimensional_array(dimension, dimension)};
  for (int i = 0; i < height; ++i) {
    memcpy(block.field[i], figure[i], width * sizeof(int));
  }
  return block;
}
