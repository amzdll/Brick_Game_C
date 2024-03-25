#include <stdio.h>
#include <string.h>

#include "defines.h"
#include "game_entities.h"
#include "services.h"

int main() {
  game_board_t game_board = initialize_game_board();
  //  for (int i = 0; i < game_board.width; ++i) {
  //    game_board.field[19][i] = 1;
  //  }
  //
  block_t* blocks = initialize_blocks();
  block_t block = blocks[6];

  block.x = 5;
  block.y = 5;
  place_block(&game_board, block);
  turn_block(&game_board, block);
//  right_shift(&game_board, block);
//  remove_block(&game_board, block);

  //  left_shift(&game_board, block);
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

  return 0;
}
