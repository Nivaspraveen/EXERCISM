#include "acronym.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *abbreviate(const char *phrase)
{
    if (!phrase || *phrase == '\0')
        return NULL;
    size_t len = strlen(phrase);
    char *acronym = malloc(len + 1);
    if (!acronym)
        return NULL;
    size_t acronym_index = 0;
    int is_new_word = 1;
    for (size_t i = 0; phrase[i] != '\0'; ++i)
    {
        char curr = phrase[i];
        if (is_new_word && isalpha(curr))
        {
            acronym[acronym_index++] = toupper(curr);
            is_new_word = 0;
        }
        else if (curr == ' ' || curr == '-')
            is_new_word = 1;
        else if (ispunct(curr))
            continue;
        else
            is_new_word = 0;
    }
    acronym[acronym_index] = '\0';
    return acronym;
}