#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H
#include <stdlib.h>

typedef struct {
   int size;
   int **matrix;
} spiral_matrix_t;

int **allocate_matrix(int size);
void free_matrix(int **matrix, int size);
spiral_matrix_t *spiral_matrix_create(int size);
void spiral_matrix_destroy(spiral_matrix_t *spiral);

#endif
