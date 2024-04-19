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
  draw_parameters(prms);
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
      draw_board(game_instance.game_board);
      //    } else if (state == SHIFTING) {
      //
    }
    call_action(get_signal(signal), &game_instance, &prms);
  }
}

int main() {
      WIN_INIT(50)
      setlocale(LC_ALL, "");
      draw_overlay();
      game_loop();
      endwin();
  return 0;
}

//
//typedef struct {
//  int **field;
//  int **next;
//  int score;
//  int high_score;
//  int level;
//  int speed;
//  int pause;
//} GameInfo_t;
//
//void userInput(UserAction_t action, bool hold);
//GameInfo_t updateCurrentState();