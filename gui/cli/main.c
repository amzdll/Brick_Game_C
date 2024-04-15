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

  draw_field(game_board);
  return 0;
}