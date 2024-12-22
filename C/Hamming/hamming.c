#include "hamming.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
    if (lhs == NULL || rhs == NULL)
        return -1;
    if (strlen(lhs) != strlen(rhs))
        return -1;

    int distance = 0;
    for (size_t i = 0; lhs[i] != '\0' && rhs[i] != '\0'; i++)
    {
        if (lhs[i] != rhs[i])
            distance++;
    }
    return distance;
}