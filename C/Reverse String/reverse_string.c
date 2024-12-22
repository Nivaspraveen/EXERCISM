#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value)
{
    if (value == NULL)
        return NULL;
    int len = strlen(value);
    char *reversed = (char *)malloc((len + 1) * sizeof(char));
    if (reversed == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        reversed[i] = value[len - 1 - i];
    reversed[len] = '\0';
    return reversed;
}