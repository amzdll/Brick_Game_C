#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "defines.h"
#include "game_entities.h"
#include "helpers.h"
#include "services.h"

int main() {
  game_board_t game_board = initialize_game_board();


  wmemset(game_board.field[0], 1, WIDTH * sizeof(int));



  game_board.field[0][0] = 0;
  for (int i = 0; i < WIDTH; ++i) {
    printf("%d\t", game_board.field[0][i]);
  }
  printf("\n");
  if (is_row_complete(game_board.field[0])) {
    printf("is full\n");
  } else {
    printf("isn't full\n");
  }

  game_board.field[0][0] = 1;
  game_board.field[0][1] = 2;
  game_board.field[0][2] = 3;
  game_board.field[0][3] = 4;
  game_board.field[0][4] = 5;

  for (int i = 0; i < WIDTH; ++i) {
    printf("%d\t", game_board.field[0][i]);
  }
  printf("\n");

  if (is_row_complete(game_board.field[0])) {
    printf("is full\n");
  } else {
    printf("isn't full\n");
  }
  //  block_t* blocks = initialize_blocks();
  // 1 3
  //      //  block_t current_block = create_block(blocks);
  //      //  while (!is_game_over(game_board, current_block)) {
  //      //    while (!is_collision(game_board, current_block)) {
  //      //      down_move(&game_board, &current_block);
  //      //    }
  //      //    //      ++n;
  //      //    current_block = create_block(blocks);
  //      //  }
  //      block_t current_block = blocks[0];
  //  current_block.x = (int)(WIDTH - current_block.width) / 2;
  //  current_block.y = 19;
  //  place_block(&game_board, current_block);
  //  block_t temp = blocks[4];
  //  temp.x = (int)(WIDTH - temp.width) / 2;
  //  temp.y = 17;
  //  place_block(&game_board, temp);
  //  if (!is_collision(game_board, temp)) {
  //    down_move(&game_board, &temp);
  //  }
  //
  //  //  printf("%s\n", is_collision(game_board, temp) ? "true" : "false");
  //
  //  printf(" \t");
  //  for (int i = 0; i < WIDTH; ++i) {
  //    printf("%d ", i);
  //  }
  //  printf(" \n");
  //  for (size_t i = 0; i < HEIGHT; ++i) {
  //    printf("%zu\t", i);
  //    for (size_t j = 0; j < WIDTH; ++j) {
  //      printf("%d ", game_board.field[i][j]);
  //    }
  //    printf("\n");
  //  }
  //
  //  free_int_two_dimensional_array(NULL, 0);
  //  //  free_blocks(blocks);
  return 0;
}

/*
        0 1 2 3 4 5 6 7 8 9
0	0 0 0 0 0 0 0 0 0 0
1	0 0 0 0 0 0 0 0 0 0
2	0 0 0 0 0 0 0 0 0 0
3	0 0 0 0 0 0 0 0 0 0
4	0 0 0 0 0 0 0 0 0 0
5	0 0 0 0 0 0 0 0 0 0
6	0 0 0 0 0 0 0 0 0 0
7	0 0 0 0 0 0 0 0 0 0
8	0 0 0 0 0 0 0 0 0 0
9	0 0 0 0 0 0 0 0 0 0
10	0 0 0 0 0 0 0 0 0 0
11	0 0 0 0 0 0 0 0 0 0
12	0 0 0 0 0 0 0 0 0 0
13	0 0 0 0 0 0 0 0 0 0
14	0 0 0 0 0 0 0 0 0 0
15	0 0 0 0 0 0 0 0 0 0
16	0 0 0 0 1 1 0 0 1 1
17	0 0 0 1 1 0 0 0 1 1
18	0 0 0 0 0 0 0 0 0 0
18	0 0 0 0 0 0 0 0 0 0
19	0 0 0 1 1 1 1 0 0 0
 */