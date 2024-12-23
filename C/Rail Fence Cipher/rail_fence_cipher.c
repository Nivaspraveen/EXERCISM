#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>

char *encode(char *text, size_t rails)
{
    if (rails == 1)
    {
        char *result = (char *)malloc(strlen(text) + 1);
        strcpy(result, text);
        return result;
    }

    size_t length = strlen(text);
    char *encoded = (char *)malloc(length + 1);
    if (encoded == NULL)
        return NULL;

    size_t index = 0;
    for (size_t r = 0; r < rails; r++)
    {
        size_t step1 = 2 * (rails - r - 1);
        size_t step2 = 2 * r;
        size_t pos = r;

        if (pos < length)
            encoded[index++] = text[pos];
        while (1)
        {
            pos += step1;
            if (step1 && pos < length)
                encoded[index++] = text[pos];
            pos += step2;
            if (step2 && pos < length)
                encoded[index++] = text[pos];
            if (pos >= length)
                break;
        }
    }

    encoded[index] = '\0';
    return encoded;
}

char *decode(char *ciphertext, size_t rails)
{
    if (rails == 1)
    {
        char *result = (char *)malloc(strlen(ciphertext) + 1);
        strcpy(result, ciphertext);
        return result;
    }

    size_t length = strlen(ciphertext);
    char *decoded = (char *)malloc(length + 1);
    if (decoded == NULL)
        return NULL;

    size_t *rail_lengths = (size_t *)malloc(rails * sizeof(size_t));
    memset(rail_lengths, 0, rails * sizeof(size_t));
    size_t pos = 0;
    int direction = 1;

    for (size_t i = 0; i < length; i++)
    {
        rail_lengths[pos]++;
        if (pos == 0)
            direction = 1;
        else if (pos == rails - 1)
            direction = -1;
        pos += direction;
    }

    size_t *rail_positions = (size_t *)malloc(rails * sizeof(size_t));
    rail_positions[0] = 0;

    for (size_t r = 1; r < rails; r++)
        rail_positions[r] = rail_positions[r - 1] + rail_lengths[r - 1];

    pos = 0;
    direction = 1;
    for (size_t i = 0; i < length; i++)
    {
        decoded[i] = ciphertext[rail_positions[pos]++];
        if (pos == 0)
            direction = 1;
        else if (pos == rails - 1)
            direction = -1;
        pos += direction;
    }

    decoded[length] = '\0';
    free(rail_lengths);
    free(rail_positions);

    return decoded;
}