#include "command_line_interface.h"

void print_overlay(void) {
  print_rectangle(0, BOARD_N + 1, 0, BOARD_M + 1);
  print_rectangle(0, BOARD_N + 1, BOARD_M + 2, BOARD_M + HUD_WIDTH + 3);

  print_rectangle(1, 3, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
  print_rectangle(4, 6, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
  print_rectangle(7, 9, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
//  print_rectangle(10, 12, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);

  MVPRINTW(2, BOARD_M + 5, "LEVEL");
  MVPRINTW(5, BOARD_M + 5, "SCORE");
  MVPRINTW(8, BOARD_M + 5, "SPEED");

  MVPRINTW(BOARD_N / 2, (BOARD_M - INTRO_MESSAGE_LEN) / 2 + 1, INTRO_MESSAGE);
}

void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  MVADDCH(top_y, left_x, ACS_ULCORNER);
  int i = left_x + 1;
  for (; i < right_x; i++) {
    MVADDCH(top_y, i, ACS_HLINE);
  }
  MVADDCH(top_y, i, ACS_URCORNER);
  for (int i = top_y + 1; i < bottom_y; i++) {
    MVADDCH(i, left_x, ACS_VLINE);
    MVADDCH(i, right_x, ACS_VLINE);
  }
  MVADDCH(bottom_y, left_x, ACS_LLCORNER);
  i = left_x + 1;
  for (; i < right_x; i++) {
    MVADDCH(bottom_y, i, ACS_HLINE);
  }
  MVADDCH(bottom_y, i, ACS_LRCORNER);
}

 void print_parameters(game_parameters_t game_parameters) {
   MVPRINTW(2, BOARD_M + 12, "%d", game_parameters.level);
   MVPRINTW(5, BOARD_M + 12, "%d", game_parameters.score);
   MVPRINTW(8, BOARD_M + 12, "%d", game_parameters.speed);
 }

void print_board(game_board_t game_board) {
  WIN_INIT(INITIAL_TIMEOUT)
  refresh();

  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      int cell_value = game_board[i][j];

      int x = j + BOARDS_BEGIN;
      int y = i + BOARDS_BEGIN;

      switch (cell_value) {
        case 0:
          MVADDCH(y, x, ' ');
          break;
        case 1:
          break;
      }
    }
  }

  refresh();
  GET_USER_INPUT;
  endwin();
}