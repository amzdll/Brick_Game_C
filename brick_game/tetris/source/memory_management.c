#include "memory_management.h"

#include "game_entities.h"

int **allocate_int_two_dimensional_array(size_t height, size_t width) {
  int **array = (int **)calloc(height, sizeof(int *));
  for (int i = 0; i < height; ++i) {
    array[i] = (int *)calloc(width, sizeof(int));
  }
  return array;
}

void free_int_two_dimensional_array(size_t height, size_t width, int**two_dimensional_array) {
  for (size_t i = 0; i < height; ++i) {
    for (size_t j = 0; j < width; ++j) {
      free(two_dimensional_array[j]);
    }
    free(two_dimensional_array[i]);
  }
}