#include "isogram.h"
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>

bool is_isogram(const char phrase[])
{
    if (phrase == NULL)
        return false;
    bool seen[26] = {false};
    for (int i = 0; phrase[i] != '\0'; i++)
    {
        char c = phrase[i];
        if (c == ' ' || c == '-')
            continue;
        c = tolower(c);
        if (c >= 'a' && c <= 'z')
        {
            int index = c - 'a';
            if (seen[index])
                return false;
            seen[index] = true;
        }
    }
    return true;
}