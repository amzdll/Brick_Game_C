#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_

#include <ncurses.h>

#include "game_entities.h"
#include "services.h"

typedef enum {
  START = 0,
  SPAWN = 1,
  MOVING = 2,
  SHIFTING = 3,
  COLLIDE = 4,
  GAME_OVER = 5,
  EXIT_STATE = 6
} game_state;

typedef enum {
  TURN = 0,
  MOVE_DOWN = 1,
  MOVE_RIGHT = 2,
  MOVE_LEFT = 3,
  ESCAPE_BTN = 4,
  ENTER_BTN = 5,
  NO_SIG = 6
} signals;

typedef void (*action)(game_board_t game_board, block_t *block);

// typedef struct game_state {
//   game_board_t game_board;
//   block_t *block_pool;
//   block_t current_block;
//   game_state current_state;
//   game_stats_t *stats;
// } game_state_t;

void spawn_action(game_board_t game_board, block_t *block);
void move_up_action(game_state_t *game_state);
void move_down_action(game_state_t *game_state);
void move_right_action(game_state_t *game_state);
void move_left_action(game_state_t *game_state);
void shifting_action(game_state_t *game_state);
void collide_action(game_state_t *game_state);
void game_over_action(game_state_t *game_state);
void exit_state_action(game_state_t *game_state);
void check_action(game_state_t *game_state);

action fsm_table[8][7] = {
    //    exit_state
    {NULL, NULL, NULL, NULL, NULL, spawn_action, NULL},
    //    {spawn_block, spawn_block, spawn_block, spawn_block, spawn_block,
    //     spawn_block, spawn_block},
    //    {moveup, movedown, moveright, moveleft, exit_state, check, check},
    //    {shifting, shifting, shifting, shifting, shifting, shifting,
    //    shifting},
    //    {collide, collide, collide, collide, collide, collide, collide},
    //    {game_over, game_over, game_over, game_over, game_over, game_over,
    //     game_over},
    //    {exit_state, exit_state, exit_state, exit_state, exit_state,
    //    exit_state,
    //     exit_state}
};

signals get_signal(int user_input);
void sigact(signals sig, game_state *state, game_stats_t *stats,
            game_board_t *game_board);

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_
