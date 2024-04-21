#include "services.h"

#include "helpers.h"

Block CreateBlock(Block* blocks) {
#ifdef __APPLE__
  uint32_t block_index = arc4random() % BLOCKS_COUNT;
#else
  int block_index = rand() % BLOCKS_COUNT;
#endif
//  block_t block = blocks[block_index];
  Block block = blocks[3];
  int** block_field = AllocateIntTwoDimensionalArray(block.field_dimension,
                                                     block.field_dimension);
  for (int i = 0; i < block.height; ++i) {
    memcpy(block_field[i], block.field[i], block.width * sizeof(int));
  }
  block.field = block_field;

  return block;
}

void PlaceBlock(GameBoard game_board, Block block) {
  for (int i = 0; i < block.height; ++i) {
    for (int j = 0; j < block.width; ++j) {
      game_board[block.y + i][block.x + j] |= block.field[i][j];
    }
  }
}

void RemoveBlock(GameBoard game_board, Block block) {
  int* game_board_cell = NULL;
  int* block_cell = NULL;
  for (int i = 0; i < block.height; ++i) {
    for (int j = 0; j < block.width; ++j) {
      game_board_cell = &game_board[block.y + i][block.x + j];
      block_cell = &block.field[i][j];
      *game_board_cell = (*game_board_cell ^ *block_cell) * !*block_cell;
    }
  }
}

void SpawnBlock(GameBoard game_board, Block block) {
  PlaceBlock(game_board, block);
}

void RotateBlock(GameBoard game_board, Block* block) {
  // todo: statement guard

  RemoveBlock(game_board, *block);
  int block_cell = 0;
  for (int i = 0; i < block->field_dimension / 2; i++) {
    for (int j = i; j < block->field_dimension - i - 1; j++) {
      block_cell = block->field[i][j];
      block->field[i][j] = block->field[block->field_dimension - 1 - j][i];
      block->field[block->field_dimension - 1 - j][i] =
          block->field[block->field_dimension - 1 - i]
                      [block->field_dimension - 1 - j];
      block->field[block->field_dimension - 1 - i]
                  [block->field_dimension - 1 - j] =
          block->field[j][block->field_dimension - 1 - i];
      block->field[j][block->field_dimension - 1 - i] = block_cell;
    }
  }
  ShiftBlockCells(block);
  size_t block_width = block->height;
  size_t block_height = block->width;
  block->width = block_width;
  block->height = block_height;

  PlaceBlock(game_board, *block);
}

void MoveLeft(GameBoard game_board, Block* block) {
  if (block->x == 0) {
    return;
  }
  for (int i = 0, j = 0; i < block->height; ++i) {
    for (; j < block->width && !block->field[i][j]; ++j);
    if (block->field[i][j] && game_board[block->y + i][block->x + j - 1]) {
      return;
    }
    j = 0;
  }

  RemoveBlock(game_board, *block);
  --block->x;
  PlaceBlock(game_board, *block);
}

void MoveRight(GameBoard game_board, Block* block) {
  // statement guard
  // for height for  last_elemnt width && last_elemnt width + 1 || ...
  if (block->x + block->width == WIDTH) {
    return;
  }
  // FIX
  for (int i = 0; i < block->height; ++i) {
    if (game_board[block->y][block->x + block->width]) {
      return;
    }
  }

  RemoveBlock(game_board, *block);
  ++block->x;
  PlaceBlock(game_board, *block);
}

void MoveDown(GameBoard game_board, Block* block) {
  RemoveBlock(game_board, *block);
  ++block->y;
  PlaceBlock(game_board, *block);
}

void GameBoardShift(GameBoard game_board, int row_index) {
  for (int i = row_index - 1; i > 0; --i) {
    memcpy(game_board[i + 1], game_board[i], WIDTH * sizeof(int));
  }
}

// 0 0 0
// 0 0 0
// 1 1 0
// 0 1 0

//  void fast_down_move() {}