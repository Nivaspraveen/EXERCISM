#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>

static const char *roman_symbols[] = {
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
};

static const unsigned int roman_values[] = {
    1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
};

static const size_t roman_count = sizeof(roman_values) / sizeof(roman_values[0]);

char *to_roman_numeral(unsigned int number)
{
    if (number > 3999)
        return NULL;
    char *result = malloc(20);
    if (!result)
        return NULL;
    result[0] = '\0';
    for (size_t i = 0; i < roman_count; i++)
    {
        while (number >= roman_values[i])
        {
            strcat(result, roman_symbols[i]);
            number -= roman_values[i];
        }
    }
    return result;
}