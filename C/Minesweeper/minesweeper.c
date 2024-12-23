#include "minesweeper.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **annotate(const char **minefield, const size_t rows) {
    if (rows == 0 || minefield == NULL) return NULL;
    
    size_t cols = strlen(minefield[0]);
    char **annotation = (char **)malloc((rows + 1) * sizeof(char *)); 
    if (!annotation) return NULL;

    for (size_t i = 0; i < rows; i++) {
        annotation[i] = (char *)malloc((cols + 1) * sizeof(char));
        if (!annotation[i]) {
            for (size_t k = 0; k < i; k++) free(annotation[k]);
            free(annotation);
            return NULL;
        }
        strcpy(annotation[i], minefield[i]);
    }
    int dir[8][2] = {
        {-1, -1}, {-1,  0}, {-1,  1},
        { 0, -1},           { 0,  1},
        { 1, -1}, { 1,  0}, { 1,  1}
    };
    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            if (minefield[row][col] == '*') continue;
            int mine_count = 0;
            for (int d = 0; d < 8; d++) {
                int new_row = (int)row + dir[d][0];
                int new_col = (int)col + dir[d][1];
                if (new_row >= 0 && (size_t)new_row < rows &&
                    new_col >= 0 && (size_t)new_col < cols &&
                    minefield[new_row][new_col] == '*') {
                    mine_count++;
                }
            }
            if (mine_count > 0) annotation[row][col] = mine_count + '0';
            else annotation[row][col] = ' ';
        }
    }
    return annotation;
}

void free_annotation(char **annotation) {
    if (!annotation) return;
    for (size_t i = 0; annotation[i] != NULL; i++) {
        free(annotation[i]);
    }
    free(annotation);
}