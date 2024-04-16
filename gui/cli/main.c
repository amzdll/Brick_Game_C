#include "fsm.h"
#include "helpers.h"

void game_loop() {
  game_instance_t game_instance = initialize_game_instance();
  game_parameters_t game_parameters = initialize_game_parameters();

  call_action(MOVE_DOWN, &game_instance, &game_parameters);
  while (game_parameters.current_state != GAME_OVER) {
    call_action(MOVE_DOWN, &game_instance, &game_parameters);
  }
  call_action(MOVE_DOWN, &game_instance, &game_parameters);
  draw_field(game_instance.game_board);
}

int main() {
  game_loop();
  game_loop();

  //  start_action(&game_instance, &game_stats);
  //  spawn_action(&game_instance, &game_stats);
  //  move_down_action(&game_instance, &game_stats);

  //  game_instance_t game_instance = initialize_game_instance();
  //
  //  game_instance.current_block = create_block(game_instance.block_pool);
  //
  //  while (!is_game_over(game_instance.game_board,
  //  game_instance.current_block)) {
  //    move_down(game_instance.game_board, &game_instance.current_block);
  //    if (is_collision(game_instance.game_board, game_instance.current_block))
  //    {
  //      game_instance.current_block = create_block(game_instance.block_pool);
  //    }
  //  }

  return 0;
}