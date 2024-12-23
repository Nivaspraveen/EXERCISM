#include "crypto_square.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static char *custom_strdup(const char *s)
{
    size_t len = strlen(s) + 1; // Include space for null terminator
    char *copy = malloc(len);
    if (copy)
        memcpy(copy, s, len);
    return copy;
}

static char *normalize(const char *input)
{
    size_t len = strlen(input);
    char *normalized = malloc(len + 1);
    if (!normalized)
        return NULL;

    size_t j = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (isalnum((unsigned char)input[i]))
            normalized[j++] = tolower((unsigned char)input[i]);
    }
    normalized[j] = '\0';
    return normalized;
}

static void find_dimensions(size_t length, size_t *rows, size_t *cols)
{
    size_t c = ceil(sqrt(length)), r = floor(sqrt(length));
    if (r * c < length)
        r++;
    *rows = r;
    *cols = c;
}

char *ciphertext(const char *input)
{
    if (!input || !*input)
        return custom_strdup("");
    char *normalized = normalize(input);
    if (!normalized)
        return NULL;
    size_t length = strlen(normalized);
    size_t rows, cols;
    find_dimensions(length, &rows, &cols);
    char *result = malloc((rows * cols) + cols + 1);
    if (!result)
    {
        free(normalized);
        return NULL;
    }
    size_t pos = 0;
    for (size_t c = 0; c < cols; c++)
    {
        for (size_t r = 0; r < rows; r++)
        {
            size_t index = r * cols + c;
            if (index < length)
                result[pos++] = normalized[index];
            else
                result[pos++] = ' ';
        }
        if (c < cols - 1)
            result[pos++] = ' ';
    }
    result[pos] = '\0';
    free(normalized);
    return result;
}