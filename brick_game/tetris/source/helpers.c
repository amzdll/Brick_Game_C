#include "helpers.h"

#include <fcntl.h>
#include <time.h>
#include <zconf.h>

bool is_collision(game_board_t game_board, block_t block) {
  if (block.height + block.y == HEIGHT) {
    return true;
  }

  for (size_t i = 0; i < block.height; ++i) {
    for (size_t j = 0; j < block.width; ++j) {
      // poka eto ponimau tolka ia i bog, zavtra budet znat' tolko bog.
      if (block.field[i][j] && game_board.field[block.y + i + 1][block.x + j] &&
          ((i + 1 < block.height && !block.field[i + 1][j]) ||
           i + 1 == block.height))
        return true;
    }
  }
  return false;
}

bool is_row_complete(int* row) {
  return !(int*)bsearch((void*)&(int){0}, row, WIDTH, sizeof(int),
                        compare_nums);
}

bool is_game_over(game_board_t game_board, block_t block) {
  return is_collision(game_board, block) && block.y == 0;
}

int compare_nums(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

void init_random_seed() {
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

// temp
void draw_field(game_board_t game_board) {
  printf(" \t");
  for (int i = 0; i < WIDTH; ++i) {
    printf("%d ", i);
  }
  printf(" \n");
  for (size_t i = 0; i < HEIGHT; ++i) {
    printf("%zu\t", i);
    for (size_t j = 0; j < WIDTH; ++j) {
      printf("%d ", game_board.field[i][j]);
    }
    printf("\n");
  }
}
