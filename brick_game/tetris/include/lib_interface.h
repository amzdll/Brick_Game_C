#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_LIB_INTERFACE_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_LIB_INTERFACE_H_

#include <stdbool.h>

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState();

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_LIB_INTERFACE_H_
