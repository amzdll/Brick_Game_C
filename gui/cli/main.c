#include "game_entities.h"
#include "helpers.h"
#include "services.h"

int main() {
  init_random_seed();
  game_board_t game_board = initialize_game_board();
  block_t* blocks = initialize_blocks();

  int n = 0;
  block_t current_block = create_block(blocks);

  while (!is_game_over(game_board, current_block)) {
    move_down(&game_board, &current_block);
    if (is_collision(game_board, current_block)) {
      current_block = create_block(blocks);
    }
    ++n;
  }
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
  //  block_t block_1 = blocks[0];
  //  block_t block_2 = blocks[0];
  //  block_t block_3 = blocks[3];
  //  block_t block_4 = blocks[3];
  //  block_t block_5 = blocks[5];
  //  block_1.y = 17;
  //  block_1.x = 0;
  //  block_2.y = 17;
  //  block_2.x = 4;
  //  block_3.y = 16;
  //  block_3.x = 8;
  //  block_4.y = 18;
  //  block_4.x = 8;
  //  block_5.y = 15;
  //  block_5.x = 7;
  //  place_block(&game_board, block_1);
  //  place_block(&game_board, block_2);
  //  place_block(&game_board, block_3);
  //  place_block(&game_board, block_4);
  //  place_block(&game_board, block_5);
  //  if (is_row_complete(game_board.field[17])) {
  //    game_board_shift(&game_board, 17);
  //  }

  draw_field(game_board);
  return 0;
}