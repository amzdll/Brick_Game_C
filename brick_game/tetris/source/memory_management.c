#include "memory_management.h"

int **allocate_int_two_dimensional_array(size_t height, size_t width) {
  int **array = (int **)calloc(height, sizeof(int *));
  for (int i = 0; i < height; ++i) {
    array[i] = (int *)calloc(width, sizeof(int));
  }
  return array;
}