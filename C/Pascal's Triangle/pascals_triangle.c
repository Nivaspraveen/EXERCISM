#include "pascals_triangle.h"
#include <stdlib.h>

#include "pascals_triangle.h"

#define MIN_SIZE(nrows) ((nrows) > 0 ? (nrows) : 1)

void
free_triangle(uint8_t **triangle, size_t rows)
{
    for (size_t i = 0; i < MIN_SIZE(rows); i++)
        free(triangle[i]);
    free(triangle);
}

uint8_t **create_triangle(size_t rows)
{
    uint8_t **triangle = calloc(MIN_SIZE(rows), sizeof(*triangle));
    if (!triangle)
        return NULL;
    if (rows == 0) {
        triangle[0] = calloc(1, sizeof(triangle[0]));
        if (!triangle[0]) {
            free(triangle);
            return NULL;
        }
        return triangle;
    }

    size_t row_size = 1;
    for (size_t i = 0; i < rows; i++, row_size++) {
        uint8_t *row = triangle[i] = calloc(rows, sizeof(*row));
        if (!row) {
            free_triangle(triangle, rows);
            return NULL;
        }
        row[0] = row[row_size - 1] = 1;
        for (size_t j = 1; j < row_size - 1; j++) {
            uint8_t *prev_row = triangle[i - 1];
            row[j] = prev_row[j - 1] + prev_row[j];
        }
    }
    return triangle;
}