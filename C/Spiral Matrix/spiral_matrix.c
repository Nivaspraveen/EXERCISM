#include <stdlib.h>
#include "spiral_matrix.h"

// Helper function to allocate a 2D matrix
int **allocate_matrix(int size)
{
    if (size <= 0)
        return NULL;
    int **matrix = malloc(size * sizeof(int *));
    if (!matrix)
        return NULL;
    for (int i = 0; i < size; i++)
    {
        matrix[i] = malloc(size * sizeof(int));
        if (!matrix[i])
        {
            for (int j = 0; j < i; j++)
                free(matrix[j]);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// Helper function to free a 2D matrix
void free_matrix(int **matrix, int size)
{
    if (!matrix)
        return;
    for (int i = 0; i < size; i++)
        free(matrix[i]);
    free(matrix);
}

spiral_matrix_t *spiral_matrix_create(int size)
{
    if (size <= 0)
    {
        spiral_matrix_t *empty = malloc(sizeof(spiral_matrix_t));
        if (!empty)
            return NULL;
        empty->size = 0;
        empty->matrix = NULL;
        return empty;
    }

    int **matrix = allocate_matrix(size);
    if (!matrix)
        return NULL;
    int value = 1, top = 0, bottom = size - 1, left = 0, right = size - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            matrix[top][i] = value++;
        top++;
        for (int i = top; i <= bottom; i++)
            matrix[i][right] = value++;
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                matrix[bottom][i] = value++;
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = value++;
            left++;
        }
    }

    spiral_matrix_t *spiral = malloc(sizeof(spiral_matrix_t));
    if (!spiral)
    {
        free_matrix(matrix, size);
        return NULL;
    }

    spiral->size = size;
    spiral->matrix = matrix;
    return spiral;
}

void spiral_matrix_destroy(spiral_matrix_t *spiral)
{
    if (!spiral)
        return;
    free_matrix(spiral->matrix, spiral->size);
    free(spiral);
}
