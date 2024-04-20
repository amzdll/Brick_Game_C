#ifdef __linux
#include <locale.h>
#include <sys/ioctl.h>
#else
#include <libintl.h>
#endif

#include "lib_interface.h"
#include "command_line_interface.h"
#include "fsm.h"
#include "helpers.h"

void GameLoop() {
  GameInstance game_instance = InitializeGameInstance();
  GameParameters parameters = InitializeGameParameters();
  GameInfo game_info = {NULL, NULL, 0,0,0,0,0};
  bool break_flag = TRUE;
  int signal = 0;
  draw_parameters(game_info);
  game_state state;

  while (break_flag) {
    state = parameters.current_state;
    if (state == GAME_OVER || state == EXIT_STATE) {
      break_flag = FALSE;
    }
    if (state == MOVING || state == START) {
      signal = GET_USER_INPUT;
      mvprintw(0, 0, "current state = %d\tsignal = %d", state,
               GetSignal(signal));

      draw_board(FillGameInfo(game_instance, parameters));
    }
    CallAction(GetSignal(signal), &game_instance, &parameters);
  }
}

int main() {
  WIN_INIT(50)
  setlocale(LC_ALL, "");
  draw_overlay();
  GameLoop();
  endwin();
  return 0;
}


// typedef struct {
//  int **field;
//  int **next;
//  int score;
//  int high_score;
//  int level;
//  int speed;
//  int pause;
//} GameInfo_t;

// void userInput(UserAction_t action, bool hold);
// GameInfo_t updateCurrentState();