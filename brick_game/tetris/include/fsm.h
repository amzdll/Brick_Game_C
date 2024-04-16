#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_

#include <ncurses.h>

#include "game_entities.h"
#include "services.h"

typedef void (*action)(game_instance_t* game_instance,
                       game_parameters_t* game_parameters);

typedef enum {
  TURN = 0,
  MOVE_DOWN = 1,
  MOVE_RIGHT = 2,
  MOVE_LEFT = 3,
  ESCAPE_BTN = 4,
  ENTER_BTN = 5,
  NO_SIG = 6
} signals;


void call_action(signals signal, game_instance_t* game_instance,
                 game_parameters_t* game_stats);

void start_action(game_instance_t* game_instance,
                  game_parameters_t* game_stats);
void spawn_action(game_instance_t* game_instance,
                  game_parameters_t* game_stats);
void rotate_action(game_instance_t* game_instance,
                   game_parameters_t* game_stats);
void move_down_action(game_instance_t* game_instance,
                      game_parameters_t* game_stats);
void move_right_action(game_instance_t* game_instance,
                       game_parameters_t* game_stats);
void move_left_action(game_instance_t* game_instance,
                      game_parameters_t* game_stats);
void collide_action(game_instance_t* game_instance,
                    game_parameters_t* game_stats);
void exit_state_action(game_instance_t* game_instance,
                       game_parameters_t* game_stats);
void game_over_action(game_instance_t* game_instance,
                      game_parameters_t* game_stats);

signals get_signal(int user_input);

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_
