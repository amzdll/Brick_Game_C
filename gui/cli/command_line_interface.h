#ifndef TETRIS_GUI_CLI_COMMAND_LINE_INTERFACE_H_
#define TETRIS_GUI_CLI_COMMAND_LINE_INTERFACE_H_

#include <ncurses.h>
#include <string.h>

#include "defines.h"
#include "game_entities.h"
#include "lib_interface.h"


void draw_overlay(void);
void draw_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void draw_parameters(GameInfo game_info);
void DrawBoard(GameInfo game_info);
// choose_game...

#endif  // TETRIS_GUI_CLI_COMMAND_LINE_INTERFACE_H_

