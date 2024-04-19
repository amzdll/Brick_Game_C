#ifndef TETRIS_GUI_CLI_COMMAND_LINE_INTERFACE_H_
#define TETRIS_GUI_CLI_COMMAND_LINE_INTERFACE_H_

#include <ncurses.h>
#include <string.h>

#include "defines.h"
#include "game_entities.h"



void draw_overlay(void);
void draw_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void draw_parameters(game_parameters_t game_parameters);
void draw_board(game_board_t game_board);
//void print_cars(board_t *game);
//void print_finished(board_t *game);
//void print_banner(game_state *stats);
//int read_banner(game_state *stats, banner_t *banner);

#endif  // TETRIS_GUI_CLI_COMMAND_LINE_INTERFACE_H_

