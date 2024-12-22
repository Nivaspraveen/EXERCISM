#include "binary.h"
#include <string.h>
#include <ctype.h>

int convert(const char *input)
{
    if (input == NULL || *input == '\0')
        return INVALID;
    int length = strlen(input), result = 0;
    for (int i = 0; i < length; i++)
    {
        char c = input[i];
        if (c != '0' && c != '1')
            return INVALID;
        result = result * 2 + (c - '0');
    }
    return result;
}