#ifndef TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_
#define TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_

#include <stdbool.h>

#include "game_entities.h"
#include "ncurses.h"

bool IsCollision(GameBoard game_board, Block block);
bool IsGameOver(GameBoard game_board, Block block);
bool IsRowComplete(const int* row);

void ClearGameBoard(GameBoard game_board);

void ShiftBlockCells(Block* block);

void draw_field(GameBoard game_board);
#endif  // TETRIS_BRICK_GAME_TETRIS_INCLUDE_HELPERS_H_
