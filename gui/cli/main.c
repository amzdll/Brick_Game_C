#ifdef __linux
#include <locale.h>
#include <sys/ioctl.h>
#else
#include <libintl.h>
#endif

#include "command_line_interface.h"
#include "fsm.h"
#include "helpers.h"

void game_loop() {
  game_instance_t game_instance = initialize_game_instance();
  game_parameters_t prms = initialize_game_parameters();

  bool break_flag = TRUE;
  int signal = 0;
  print_parameters(prms);
  game_state state;
  while (break_flag) {
    state = prms.current_state;
    if (state == GAME_OVER || state == EXIT_STATE) {
      break_flag = FALSE;
    }

    if (state == MOVING || state == START) {
      signal = GET_USER_INPUT;
      mvprintw(0, 0, "current state = %d\tsignal = %d", state,
               get_signal(signal));
      print_board(game_instance.game_board);
      //    } else if (state == SHIFTING) {
      //
    }
    call_action(get_signal(signal), &game_instance, &prms);
  }
}

int main() {
  WIN_INIT(50)
  setlocale(LC_ALL, "");
  print_overlay();
  game_loop();
  endwin();
  int a[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1};
  if (is_row_complete(a)) {
    printf("hui\n");
  }
  //
//  game_instance_t game_instance = initialize_game_instance();
//  game_parameters_t prms = initialize_game_parameters();
//  game_instance.current_block = game_instance.block_pool[1];
//  game_instance.current_block.y = 3;
//  place_block(game_instance.game_board, game_instance.current_block);
//  rotate_action(&game_instance, &prms);
//  draw_field(game_instance.current_block.field);

  //  game_instance.current_block = game_instance.block_pool[0];
  //  game_instance.current_block.y = 18;
  //  game_instance.current_block.x = 4;
  //  move_down_action(&game_instance, &prms);
  //  game_instance.current_block = game_instance.block_pool[3];
  //  game_instance.current_block.y = 17;
  //  game_instance.current_block.x = 8;
  ////  place_block(game_instance.game_board, game_instance.current_block);
  //  //  if (is_row_complete(game_instance.game_board[19])) {
  //
  //  call_action(MOVE_DOWN, &game_instance, &prms);
  //  call_action(MOVE_DOWN, &game_instance, &prms);
  //  call_action(MOVE_DOWN, &game_instance, &prms);
  //  call_action(MOVE_DOWN, &game_instance, &prms);
  //  move_down_action(&game_instance, &prms);
  //  move_down_action(&game_instance, &prms);
  //  move_down_action(&game_instance, &prms);
  //  move_down_action(&game_instance, &prms);
  //    printf("hui\n");
  //  }
  //  move_left(game_instance.game_board, &game_instance.current_block);
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
