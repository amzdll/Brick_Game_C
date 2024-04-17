#include <libintl.h>

#include "command_line_interface.h"
#include "fsm.h"
#include "helpers.h"

void game_loop() {
  //
  //  call_action(MOVE_DOWN, &game_instance, &game_parameters);
  //  while (game_parameters.current_state != GAME_OVER) {
  //    call_action(MOVE_DOWN, &game_instance, &game_parameters);
  //  }
  //  call_action(MOVE_DOWN, &game_instance, &game_parameters);
  //  draw_field(game_instance.game_board);

  game_instance_t game_instance = initialize_game_instance();
  game_parameters_t prms = initialize_game_parameters();

  bool break_flag = TRUE;
  int signal = 0;
  print_parameters(prms);
  while (break_flag) {
    game_state state = prms.current_state;
    if (state == GAME_OVER || state == EXIT_STATE) break_flag = FALSE;
    //
    call_action(get_signal(signal), &game_instance, &prms);
    //
    if (state == MOVING || state == START) {
      signal = GET_USER_INPUT;
    }
    print_board(game_instance.game_board);
  }
}

int main() {
  WIN_INIT(50)
  setlocale(LC_ALL, "");
  print_overlay();
  game_loop();
  endwin();
  return 0;
}
