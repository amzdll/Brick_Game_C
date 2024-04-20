#ifndef TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_
#define TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_

#include <string.h>

#include "game_entities.h"

void PlaceBlock(GameBoard game_board, Block block);
void RemoveBlock(GameBoard game_board, Block block);

// block movement logic
void SpawnBlock(GameBoard game_board, Block block);
void RotateBlock(GameBoard game_board, Block* block);
void MoveLeft(GameBoard game_board, Block* block);
void MoveRight(GameBoard game_board, Block* block);
void MoveDown(GameBoard game_board, Block* block);
void ForceMoveDown(GameBoard game_board, Block* block);

// game board logic
void GameBoardShift(GameBoard game_board, int row_index);

#endif  // TETRIS_SRC_BRICK_GAME_TETRIS_INCLUDE_SERVICES_H_
