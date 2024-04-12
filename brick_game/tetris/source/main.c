#include <stdio.h>

#include "defines.h"
#include "game_entities.h"
#include "helpers.h"
#include "services.h"

int main() {
  game_board_t game_board = initialize_game_board();

  block_t* blocks = initialize_blocks();
  //  block_t current_block = create_block(blocks);

  block_t current_block = blocks[1];
  block_t temp = blocks[2];
  current_block.x = 0;
  temp.x = 3;

  //  turn_block(&game_board, current_block);
  place_block(&game_board, temp);
  place_block(&game_board, current_block);
//  right_shift(&game_board, &current_block);
  //  right_shift(&game_board, &current_block);
  //  right_shift(&game_board, &current_block);
  //  right_shift(&game_board, &current_block);

//  left_shift(&game_board, &current_block);
  //  while (!is_game_over(game_board, current_block)) {
  //    while (!is_collision(game_board, current_block)) {
  //      down_move(&game_board, &current_block);
  //    }
  //    current_block = create_block(blocks);
  //  }

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

  free_int_two_dimensional_array()
  return 0;
}
