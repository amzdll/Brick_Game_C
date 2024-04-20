#include "game_entities.h"

GameInstance InitializeGameInstance() {
#ifdef __linux__
  initialize_random_seed();
#endif
  return (GameInstance){
      AllocateIntTwoDimensionalArray((size_t)HEIGHT, (size_t)WIDTH),
      (Block){}, InitializeBlocks()};
}

void InitializeRandomSeed() {
  unsigned int seed = time(NULL);
  int fd = open("/dev/urandom", O_RDONLY);
  if (fd != -1) {
    size_t bytes_read = read(fd, &seed, sizeof(seed));
    if (bytes_read != sizeof(seed)) {
      seed = time(NULL);
    }
    close(fd);
  }
  srand(seed);
}

GameParameters InitializeGameParameters() {
  return (GameParameters){0, 1, 1, START};
}

Block *InitializeBlocks() {
  Block *blocks = (Block *)calloc(BLOCKS_COUNT, sizeof(Block));

  blocks[0] = InitializeBlock(1, 4, I_BLOCK);
  blocks[1] = InitializeBlock(2, 3, J_BLOCK);
  blocks[2] = InitializeBlock(2, 3, L_BLOCK);
  blocks[3] = InitializeBlock(2, 2, O_BLOCK);
  blocks[4] = InitializeBlock(2, 3, S_BLOCK);
  blocks[5] = InitializeBlock(2, 3, Z_BLOCK);
  blocks[6] = InitializeBlock(2, 3, T_BLOCK);

  return blocks;
}

Block InitializeBlock(size_t height, size_t width, int (*figure)[width]) {
  size_t dimension = height > width ? height : width;
  Block block = {block.x = (int)(WIDTH - width) / 2,
                   0,
                   height,
                   width,
                   dimension,
                   AllocateIntTwoDimensionalArray(dimension, dimension)};
  for (int i = 0; i < height; ++i) {
    memcpy(block.field[i], figure[i], width * sizeof(int));
  }
  return block;
}
