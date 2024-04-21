#include "fsm.h"

#include "helpers.h"

const FSMAction kActionTable[8][8] = {
    // START
    {NULL, NULL, NULL, NULL, NULL, ExitStateAction, StartAction, NULL},
    // SPAWN
    {SpawnAction, SpawnAction, SpawnAction, SpawnAction, SpawnAction,
     SpawnAction, SpawnAction, NULL},
    // MOVING
    {RotateAction, MoveDownAction, MoveRightAction, MoveLeftAction,
     ForceMoveDownAction, ExitStateAction, NULL, NULL},
    // SHIFTING
    {ShiftAction, ShiftAction, ShiftAction, ShiftAction, ShiftAction, NULL,
     NULL, NULL},
    // COLLIDE
    {CollideAction, CollideAction, CollideAction, CollideAction, CollideAction,
     CollideAction, CollideAction, NULL},
    // GAME_OVER
    {GameOverAction, GameOverAction, GameOverAction, GameOverAction,
     GameOverAction, GameOverAction, GameOverAction, NULL},
    // EXIT_STATE
    {ExitStateAction, ExitStateAction, ExitStateAction, ExitStateAction,
     ExitStateAction, ExitStateAction, ExitStateAction, NULL},
};

void CallAction(signals signal, GameInstance* game_instance,
                GameParameters* game_stats) {
  FSMAction pAction = kActionTable[game_stats->current_state][signal];
  if (pAction) {
    pAction(game_instance, game_stats);
  }
}

signals GetSignal(int user_input) {
  signals signal = kNoSig;
  if (user_input == KEY_UP)
    signal = kMoveUpSig;
  else if (user_input == KEY_DOWN)
    signal = kMoveDownSig;
  else if (user_input == KEY_LEFT)
    signal = kMoveLeftSig;
  else if (user_input == KEY_RIGHT)
    signal = kMoveRightSig;
  else if (user_input == ESCAPE)
    signal = kExitSig;
  else if (user_input == ENTER_KEY)
    signal = kStartSig;
  else if (user_input == SPACE_KEY)
    signal = kForceMoveDownSig;

  return signal;
}

void StartAction(GameInstance* game_instance, GameParameters* game_stats) {
  if (game_instance) {
    ClearGameBoard(game_instance->game_board);
  }
  game_stats->current_state = SPAWN;
}

void SpawnAction(GameInstance* game_instance, GameParameters* game_stats) {
  game_instance->current_block = CreateBlock(game_instance->block_pool);
  SpawnBlock(game_instance->game_board, game_instance->current_block);
  game_stats->current_state = MOVING;
}

void ShiftAction(GameInstance* game_instance, GameParameters* game_parameters) {
  if (IsCollision(game_instance->game_board, game_instance->current_block)) {
    game_parameters->current_state = COLLIDE;
  } else {
    //    move_down(game_instance->game_board, &game_instance->current_block);
    game_parameters->current_state = MOVING;
  }
}

void RotateAction(GameInstance* game_instance, GameParameters* game_stats) {
  if (IsCollision(game_instance->game_board, game_instance->current_block)) {
    game_stats->current_state = COLLIDE;
  } else {
    RotateBlock(game_instance->game_board, &game_instance->current_block);
    game_stats->current_state = SHIFTING;
  }
}
void MoveDownAction(GameInstance* game_instance, GameParameters* game_stats) {
  if (IsCollision(game_instance->game_board, game_instance->current_block)) {
    game_stats->current_state = COLLIDE;
  } else {
    MoveDown(game_instance->game_board, &game_instance->current_block);
    game_stats->current_state = SHIFTING;
  }
}

void ForceMoveDownAction(GameInstance* game_instance,
                         GameParameters* game_parameters) {
  while (
      !IsCollision(game_instance->game_board, game_instance->current_block)) {
    MoveDown(game_instance->game_board, &game_instance->current_block);
    game_parameters->current_state = COLLIDE;
  }
}

void MoveRightAction(GameInstance* game_instance, GameParameters* game_stats) {
  if (IsCollision(game_instance->game_board, game_instance->current_block)) {
    game_stats->current_state = COLLIDE;
  } else {
    MoveRight(game_instance->game_board, &game_instance->current_block);
    game_stats->current_state = SHIFTING;
  }
}
void MoveLeftAction(GameInstance* game_instance, GameParameters* game_stats) {
  if (IsCollision(game_instance->game_board, game_instance->current_block)) {
    game_stats->current_state = COLLIDE;
  } else {
    MoveLeft(game_instance->game_board, &game_instance->current_block);
    game_stats->current_state = SHIFTING;
  }
}
void CollideAction(GameInstance* game_instance, GameParameters* game_stats) {
  if (game_instance->current_block.y == 0) {
    game_stats->current_state = GAME_OVER;
  } else {
    for (int i = 0; i < game_instance->current_block.height; ++i) {
      if (IsRowComplete(
              game_instance->game_board[game_instance->current_block.y + i])) {
        GameBoardShift(game_instance->game_board,
                       (int)game_instance->current_block.y + i);
      }
    }
    game_stats->current_state = SPAWN;
  }
}
void ExitStateAction(GameInstance* game_instance, GameParameters* game_stats) {
  // free
  return;
}
void GameOverAction(GameInstance* game_instance, GameParameters* game_stats) {
  ClearGameBoard(game_instance->game_board);
  game_stats->current_state = START;
}

// void game_over(params_t *prms) { print_banner(prms->stats); }

// void exit_tate(params_t *prms) { *prms->state = EXIT_STATE; }
