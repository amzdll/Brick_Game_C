#include "fsm.h"

void sigact(signals sig, game_state *state, game_stats_t *stats, game_board_t *game_board,
            struct block *current_block) {
  params_t prms;
  prms.stats = stats;
  prms.state = state;
  prms.map = map;
  prms.frog_pos = frog_pos;

  action act = fsm_table[*state][sig];

  if (act) {
    act(&prms);
  }
}

signals get_signal(int user_input) {
  signals signal = NO_SIG;
  if (user_input == KEY_UP)
    signal = TURN;
  else if (user_input == KEY_DOWN)
    signal = MOVE_DOWN;
  else if (user_input == KEY_LEFT)
    signal = MOVE_LEFT;
  else if (user_input == KEY_RIGHT)
    signal = MOVE_RIGHT;
  else if (user_input == ESCAPE)
    signal = ESCAPE_BTN;
  else if (user_input == KEY_ENTER)
    signal = ENTER_BTN;

  return signal;
}

void shifting(params_t *prms) {
  shift_map(prms->map);

  if (check_collide(prms->frog_pos, prms->map))
    *prms->state = COLLIDE;
  else {
    *prms->state = MOVING;
    print_board(prms->map, prms->frog_pos);
    print_stats(prms->stats);
  }
}

void check(params_t *prms) {
  if (check_collide(prms->frog_pos, prms->map))
    *prms->state = COLLIDE;
  else if (check_finish_state(prms->frog_pos, prms->map))
    *prms->state = REACH;
  else
    *prms->state = SHIFTING;
}

// void spawn(params_t *prms) {
//   if (prms->stats->level > LEVEL_CNT)
//     *prms->state = GAMEOVER;
//   else {
//     if (!lvlproc(prms->map, prms->stats)) {
//       fill_finish(prms->map->finish);
//       print_finished(prms->map);
//       frogpos_init(prms->frog_pos);
//       *prms->state = MOVING;
//     } else
//       *prms->state = EXIT_STATE;
//   }
// }

void moveup(params_t *prms) {
  if (prms->frog_pos->y != 1) {
    CLEAR_BACKPOS(prms->frog_pos->y, prms->frog_pos->x);
    prms->frog_pos->y -= 2;
  }

  check(prms);
}

void movedown(params_t *prms) {
  if (prms->frog_pos->y != BOARD_N) {
    CLEAR_BACKPOS(prms->frog_pos->y, prms->frog_pos->x);
    prms->frog_pos->y += 2;
  }

  check(prms);
}

void moveright(params_t *prms) {
  if (prms->frog_pos->x != BOARD_M) {
    CLEAR_BACKPOS(prms->frog_pos->y, prms->frog_pos->x);
    prms->frog_pos->x++;
  }

  check(prms);
}

void moveleft(params_t *prms) {
  if (prms->frog_pos->x != 1) {
    CLEAR_BACKPOS(prms->frog_pos->y, prms->frog_pos->x);
    prms->frog_pos->x--;
  }

  check(prms);
}

void reach(params_t *prms) {
  prms->stats->score += 1;
  add_proggress(prms->map);
  if (check_level_compl(prms->map)) {
    prms->stats->level++;
    prms->stats->speed++;
    *prms->state = SPAWN;
  } else {
    frogpos_init(prms->frog_pos);
    print_finished(prms->map);
    *prms->state = MOVING;
  }
}

void collide(params_t *prms) {
  if (prms->stats->lives) {
    prms->stats->lives--;
    frogpos_init(prms->frog_pos);
    *prms->state = MOVING;
  } else
    *prms->state = GAMEOVER;
}

void game_over(params_t *prms) { print_banner(prms->stats); }

void exit_tate(params_t *prms) { *prms->state = EXIT_STATE; }