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
  GameInstance game_instance2 = InitializeGameInstance();
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




    DrawBoard(FillGameInfo(game_instance2, parameters));
    DrawBoard(FillGameInfo(game_instance, parameters));
    if (state == MOVING || state == START) {
      signal = GET_USER_INPUT;
    }
    mvprintw(0, 0, "current state = %d\tsignal = %d", state,
             GetSignal(signal));
    CallAction(GetSignal(signal), &game_instance, &parameters);
  }
}

int main() {
//  GameInstance game_instance = InitializeGameInstance();
//  GameParameters parameters = InitializeGameParameters();
//  GameInfo game_info = {NULL, NULL, 0,0,0,0,0};
//
//  Block block = game_instance.block_pool[0];
//  block.x = 0;
//  block.y = 15;
//  game_instance.current_block = block;
//  RotateBlock(game_instance.game_board, &game_instance.current_block);
//  MoveDown(game_instance.game_board, &game_instance.current_block);
//  for (int i = 18; i < 20; ++i) {
//    for (int j = 1; j < WIDTH; ++j) {
//      game_instance.game_board[i][j] = 1;
//    }
//  }
//
////  if (IsRowComplete(game_instance.game_board[19])) {
////    GameBoardShift(game_instance.game_board, 19);
////  }
//
//  for (int i = 0; i < game_instance.current_block.height; ++i) {
//    if (IsRowComplete(game_instance.game_board[game_instance.current_block.y + i])) {
//      GameBoardShift(game_instance.game_board,
//                     (int)game_instance.current_block.y + i);
//    }
//  }

//  for (int i = 18; i < 20; ++i) {
//    for (int j = 1; j < WIDTH; ++j) {
//      game_instance.game_board[i][j] = 1;
//    }
//  }
//
//  for (int j = 1; j < 6; ++j) {
//    game_instance.game_board[17][j] = 1;
//  }
//
//  for (int i = 0; i < game_instance.current_block.height; ++i) {
//    if (IsRowComplete(game_instance.game_board[game_instance.current_block.y + i])) {
//      GameBoardShift(game_instance.game_board,
//                     (int)game_instance.current_block.y + i);
//    }
//  }

//  draw_field(game_instance.game_board);

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


// fix: horizontal line - rotate

//
//
//2   2
//1   3
//1 1 1
//1 1 0