#include "memory_management.h"

int **allocate_int_two_dimensional_array(size_t height, size_t width) {
  int **array = (int **)calloc(height, sizeof(int *));
  for (int i = 0; i < height; ++i) {
    array[i] = (int *)calloc(width, sizeof(int));
  }
  return array;
}

void free_int_two_dimensional_array(int **two_dimensional_array,
                                    size_t height) {
  for (size_t i = 0; i < height; ++i) {
    free(two_dimensional_array[i]);
  }
  free(two_dimensional_array);
}

//void free_blocks(block_t *blocks) {
//  for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
//    for (size_t j = 0; j < blocks[i].height; ++j) {
//      free(blocks[i].field[j]);
//    }
//    free(blocks[i].field);
//  }
//}
