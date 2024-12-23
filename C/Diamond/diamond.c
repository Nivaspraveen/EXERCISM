#include "diamond.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **make_diamond(const char letter) {
    int n = letter - 'A' + 1, size = 2 * n - 1;
    char **diamond = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        diamond[i] = (char *)malloc((size + 1) * sizeof(char));
        memset(diamond[i], ' ', size);
        diamond[i][size] = '\0';
    }
    for (int i = 0; i < n; i++) {
        diamond[i][n - i - 1] = 'A' + i; 
        diamond[i][n + i - 1] = 'A' + i; 
        diamond[size - i - 1][n - i - 1] = 'A' + i; 
        diamond[size - i - 1][n + i - 1] = 'A' + i;
    }
    return diamond;
}

void free_diamond(char **diamond) {
    int n = n = (strlen(diamond[0]) + 1) / 2, size = 2 * n - 1;
    for (int i = 0; i < size; i++)  free(diamond[i]); 
    free(diamond);
}