#include "lib_interface.h"

void UserInput(UserAction action, bool hold) {
  return;
}

GameInfo UpdateCurrentState() {
  GameInfo result;
  return result;
}
GameInfo FillGameInfo(GameInstance game_instance, GameParameters game_parameters) {
  return (GameInfo) {
    game_instance.game_board,
        NULL,
        game_parameters.score,
        0,
        game_parameters.level,
        game_parameters.speed,
        false
  };
}
