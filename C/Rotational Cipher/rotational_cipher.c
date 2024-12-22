#include "rotational_cipher.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *rotate(const char *text, int shift_key)
{
    if (text == NULL)
        return NULL;
    size_t len = strlen(text);
    char *result = malloc(len + 1);
    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < len; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            if (isupper(c))
                result[i] = 'A' + (c - 'A' + shift_key) % 26;
            else if (islower(c))
                result[i] = 'a' + (c - 'a' + shift_key) % 26;
        }
        else
            result[i] = c;
    }
    result[len] = '\0';
    return result;
}