#include "fsm.h"

#include "helpers.h"

action fsm_table[8][8] = {
    // START
    {NULL, NULL, NULL, NULL, NULL, exit_state_action, start_action, NULL},
    // SPAWN
    {spawn_action, spawn_action, spawn_action, spawn_action, spawn_action,
     spawn_action, spawn_action, spawn_action},
    // MOVING
    {rotate_action, move_down_action, move_right_action, move_left_action,
     force_move_down_action, exit_state_action, NULL, NULL},
    // SHIFTING
    {shift_action, shift_action, shift_action, shift_action, shift_action, NULL,
     NULL, NULL},
    // COLLIDE
    {collide_action, collide_action, collide_action, collide_action,
     collide_action, collide_action, collide_action, NULL},
    // GAME_OVER
    {game_over_action, game_over_action, game_over_action, game_over_action,
     game_over_action, game_over_action, game_over_action, NULL},
    // EXIT_STATE
    {exit_state_action, exit_state_action, exit_state_action, exit_state_action,
     exit_state_action, exit_state_action, exit_state_action, NULL},
};

void call_action(signals signal, game_instance_t* game_instance,
                 game_parameters_t* game_parameters) {
  action action = fsm_table[game_parameters->current_state][signal];

  if (action) {
    action(game_instance, game_parameters);
  }
}

signals get_signal(int user_input) {
  signals signal = NO_SIG;
  if (user_input == KEY_UP)
    signal = MOVE_UP;
  else if (user_input == KEY_DOWN)
    signal = MOVE_DOWN;
  else if (user_input == KEY_LEFT)
    signal = MOVE_LEFT;
  else if (user_input == KEY_RIGHT)
    signal = MOVE_RIGHT;
  else if (user_input == ESCAPE)
    signal = ESCAPE_BTN;
  else if (user_input == ENTER_KEY)
    signal = ENTER_BTN;
  else if (user_input == SPACE_KEY)
    signal = SPACE_BTN;

  return signal;
}

void start_action(game_instance_t* game_instance,
                  game_parameters_t* game_parameters) {
  if (game_instance) {
    clear_game_board(game_instance->game_board);
  }
  game_parameters->current_state = SPAWN;
}

void spawn_action(game_instance_t* game_instance,
                  game_parameters_t* game_parameters) {
  game_instance->current_block = create_block(game_instance->block_pool);
  spawn_block(game_instance->game_board, game_instance->current_block);
  game_parameters->current_state = MOVING;
}

void shift_action(game_instance_t* game_instance,
                  game_parameters_t* game_parameters) {
  if (is_collision(game_instance->game_board, game_instance->current_block)) {
    game_parameters->current_state = COLLIDE;
  } else {
    //    move_down(game_instance->game_board, &game_instance->current_block);
    game_parameters->current_state = MOVING;
  }
}

void rotate_action(game_instance_t* game_instance,
                   game_parameters_t* game_parameters) {
  if (is_collision(game_instance->game_board, game_instance->current_block)) {
    game_parameters->current_state = COLLIDE;
  } else {
    rotate_block(game_instance->game_board, &game_instance->current_block);
    game_parameters->current_state = SHIFTING;
  }
}
void move_down_action(game_instance_t* game_instance,
                      game_parameters_t* game_parameters) {
  if (is_collision(game_instance->game_board, game_instance->current_block)) {
    game_parameters->current_state = COLLIDE;
  } else {
    move_down(game_instance->game_board, &game_instance->current_block);
    game_parameters->current_state = SHIFTING;
  }
}

void force_move_down_action(game_instance_t* game_instance,
                            game_parameters_t* game_parameters) {
  if (is_collision(game_instance->game_board, game_instance->current_block)) {
    game_parameters->current_state = COLLIDE;
  } else {
    while (!is_collision(game_instance->game_board,
                         game_instance->current_block)) {
      move_down(game_instance->game_board, &game_instance->current_block);
      game_parameters->current_state = COLLIDE;
    }
  }
}

void move_right_action(game_instance_t* game_instance,
                       game_parameters_t* game_parameters) {
  if (is_collision(game_instance->game_board, game_instance->current_block)) {
    game_parameters->current_state = COLLIDE;
  } else {
    move_right(game_instance->game_board, &game_instance->current_block);
    game_parameters->current_state = SHIFTING;
  }
}
void move_left_action(game_instance_t* game_instance,
                      game_parameters_t* game_parameters) {
  if (is_collision(game_instance->game_board, game_instance->current_block)) {
    game_parameters->current_state = COLLIDE;
  } else {
    move_left(game_instance->game_board, &game_instance->current_block);
    game_parameters->current_state = SHIFTING;
  }
}
void collide_action(game_instance_t* game_instance,
                    game_parameters_t* game_parameters) {
  if (game_instance->current_block.y == 0) {
    game_parameters->current_state = GAME_OVER;
  } else {
    for (int i = 0; i < game_instance->current_block.height; ++i) {
      if (is_row_complete(
              game_instance->game_board[game_instance->current_block.y + i])) {
        for (int j = 0; j < WIDTH; ++j) {
          mvprintw(
              31, j, "%c ",
              game_instance
                      ->game_board[(int)game_instance->current_block.y + i][j]
                  ? '#'
                  : '0');
        }
        game_board_shift(game_instance->game_board,
                         (int)game_instance->current_block.y + i);
      }
    }
    game_parameters->current_state = SPAWN;
  }
}
void exit_state_action(game_instance_t* game_instance,
                       game_parameters_t* game_parameters) {
  // free
  return;
}
void game_over_action(game_instance_t* game_instance,
                      game_parameters_t* game_parameters) {
  clear_game_board(game_instance->game_board);
  game_parameters->current_state = START;
}

// void game_over(params_t *prms) { print_banner(prms->stats); }

// void exit_tate(params_t *prms) { *prms->state = EXIT_STATE; }