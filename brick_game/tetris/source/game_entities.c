#include "game_entities.h"

game_instance_t initialize_game_instance() {
#ifdef __linux__
  initialize_random_seed();
#endif
  return (game_instance_t){
      allocate_int_two_dimensional_array((size_t)HEIGHT, (size_t)WIDTH),
      (block_t){}, initialize_blocks()};
}

void initialize_random_seed() {
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

game_parameters_t initialize_game_parameters() {
  return (game_parameters_t){0, 1, 1, START};
}

block_t *initialize_blocks() {
  block_t *blocks = (block_t *)calloc(BLOCKS_COUNT, sizeof(block_t));

  blocks[0] = initialize_block(1, 4, I_BLOCK);
  blocks[1] = initialize_block(2, 3, J_BLOCK);
  blocks[2] = initialize_block(2, 3, L_BLOCK);
  blocks[3] = initialize_block(2, 2, O_BLOCK);
  blocks[4] = initialize_block(2, 3, S_BLOCK);
  blocks[5] = initialize_block(2, 3, Z_BLOCK);
  blocks[6] = initialize_block(2, 3, T_BLOCK);

  return blocks;
}

block_t initialize_block(size_t height, size_t width, int (*figure)[width]) {
  size_t dimension = height > width ? height : width;
  block_t block = {0, 0, height, width,
                   allocate_int_two_dimensional_array(dimension, dimension)};
  for (int i = 0; i < height; ++i) {
    memcpy(block.field[i], figure[i], width * sizeof(int));
  }
  return block;
}
