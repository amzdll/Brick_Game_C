#include "command_line_interface.h"

void draw_overlay(void) {
  draw_rectangle(0, BOARD_N + 1, 0, BOARD_M + 1);
  draw_rectangle(0, BOARD_N + 1, BOARD_M + 2, BOARD_M + HUD_WIDTH + 3);

  draw_rectangle(1, 3, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
  draw_rectangle(4, 6, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
  draw_rectangle(7, 9, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);

  MVPRINTW(2, BOARD_M + 5, "LEVEL");
  MVPRINTW(5, BOARD_M + 5, "SCORE");
  MVPRINTW(8, BOARD_M + 5, "SPEED");

  MVPRINTW(BOARD_N / 2, (BOARD_M - INTRO_MESSAGE_LEN) / 2 + 1, INTRO_MESSAGE);
}

void draw_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
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

void draw_parameters(game_parameters_t game_parameters) {
  MVPRINTW(2, BOARD_M + 12, "%d", game_parameters.level);
  MVPRINTW(5, BOARD_M + 12, "%d", game_parameters.score);
  MVPRINTW(8, BOARD_M + 12, "%d", game_parameters.speed);
}

void draw_board(game_board_t game_board) {
  for (int i = 1; i < HEIGHT + 1; i++) {
    for (int j = 1; j < WIDTH + 1; j++) {
      game_board[i - 1][j - 1] ? MVADDCH(i, j, '#') : MVADDCH(i, j, '-');
    }
  }
}
//  for (int i = MAP_PADDING + 1; i < BOARD_N - MAP_PADDING + 1; i++) {
//    if (i % 2 == (MAP_PADDING + 1) % 2) {
//      for (int j = 1; j < BOARD_M + 1; j++) {
////        ACS_BLOCK
//        MVADDCH(i, j, ' ');
//      }
//    } else {
//      for (int j = 1; j < BOARD_M + 1; j++) {
//        if (game_board[i - MAP_PADDING - 1][j - 1] == 0)
//          MVADDCH(i, j, ' ');
//        else
//          MVADDCH(i, j, '#');
//      }
//    }
//  }
//}