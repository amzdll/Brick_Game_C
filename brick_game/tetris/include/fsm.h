#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_

#include <ncurses.h>

#include "game_entities.h"
#include "services.h"

typedef void (*FSMAction)(GameInstance* game_instance,
                          GameParameters* game_parameters);

typedef enum {
  kMoveUpSig = 0,
  kMoveDownSig = 1,
  kMoveRightSig = 2,
  kMoveLeftSig = 3,
  kForceMoveDownSig = 4,
  kExitSig = 5,
  kStartSig = 6,
  kNoSig = 7
} signals;


void CallAction(signals signal, GameInstance* game_instance,
                GameParameters* game_stats);
signals GetSignal(int user_input);


//  FSM states action
void StartAction(GameInstance* game_instance, GameParameters* game_stats);
void SpawnAction(GameInstance* game_instance, GameParameters* game_stats);
void ShiftAction(GameInstance* game_instance, GameParameters* game_parameters);
void RotateAction(GameInstance* game_instance, GameParameters* game_stats);
void MoveDownAction(GameInstance* game_instance, GameParameters* game_stats);
void MoveRightAction(GameInstance* game_instance, GameParameters* game_stats);
void MoveLeftAction(GameInstance* game_instance, GameParameters* game_stats);
void ForceMoveDownAction(GameInstance* game_instance,
                         GameParameters* game_parameters);
void CollideAction(GameInstance* game_instance, GameParameters* game_stats);
void ExitStateAction(GameInstance* game_instance, GameParameters* game_stats);
void GameOverAction(GameInstance* game_instance, GameParameters* game_stats);
#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_FSM_H_
