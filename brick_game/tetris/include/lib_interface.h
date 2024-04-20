#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_LIB_INTERFACE_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_LIB_INTERFACE_H_

#include <stdbool.h>

#include "fsm.h"
#include "game_entities.h"

typedef enum {
  kStart,
  kPause,
  kTerminate,
  kLeft,
  kRight,
  kUp,
  kDown,
  kAction
} UserAction;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo;

GameInfo FillGameInfo(GameInstance game_instance, GameParameters game_parameters);

void UserInput(UserAction action, bool hold);
GameInfo UpdateCurrentState();

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_LIB_INTERFACE_H_
