#include "saddle_points.h"
#include <stdlib.h>
#include <stdbool.h>

static uint8_t find_row_max(size_t columns, uint8_t row[columns])
{
    uint8_t max = row[0];
    for (size_t col = 1; col < columns; col++)
    {
        if (row[col] > max)
            max = row[col];
    }
    return max;
}

static uint8_t find_column_min(size_t rows, size_t columns, uint8_t matrix[rows][columns], size_t col_index)
{
    uint8_t min = matrix[0][col_index];
    for (size_t row = 1; row < rows; row++)
    {
        if (matrix[row][col_index] < min)
            min = matrix[row][col_index];
    }
    return min;
}

saddle_points_t *saddle_points(size_t rows, size_t columns, uint8_t matrix[rows][columns])
{
    if (rows == 0 || columns == 0)
    {
        saddle_points_t *result = malloc(sizeof(saddle_points_t));
        result->count = 0;
        result->points = NULL;
        return result;
    }
    saddle_point_t *points = malloc(rows * columns * sizeof(saddle_point_t));
    size_t count = 0;
    for (size_t row = 0; row < rows; row++)
    {
        uint8_t row_max = find_row_max(columns, matrix[row]);
        for (size_t col = 0; col < columns; col++)
        {
            if (matrix[row][col] == row_max)
            {
                uint8_t col_min = find_column_min(rows, columns, matrix, col);
                if (matrix[row][col] == col_min)
                {
                    points[count].row = row + 1;
                    points[count].column = col + 1;
                    count++;
                }
            }
        }
    }
    saddle_points_t *result = malloc(sizeof(saddle_points_t));
    result->count = count;
    result->points = realloc(points, count * sizeof(saddle_point_t));
    return result;
}

void free_saddle_points(saddle_points_t *result)
{
    if (result)
    {
        free(result->points);
        free(result);
    }
}