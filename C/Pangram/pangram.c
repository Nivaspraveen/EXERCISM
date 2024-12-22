#include "pangram.h"
#include <ctype.h>
#include <stddef.h>

bool is_pangram(const char *sentence)
{
    if (sentence == NULL)
        return false;
    bool seen[26] = {0};
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        char c = tolower(sentence[i]);
        if (c >= 'a' && c <= 'z')
            seen[c - 'a'] = true;
    }
    for (int i = 0; i < 26; i++)
    {
        if (!seen[i])
            return false;
    }
    return true;
}