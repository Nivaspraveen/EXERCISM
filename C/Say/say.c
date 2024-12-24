#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "say.h"

const char *units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *thousands[] = {"", "thousand", "million", "billion"};

static char *strdup(const char *str) {
    size_t len = strlen(str) + 1;
    char *copy = malloc(len);
    if (copy)  memcpy(copy, str, len);
    return copy;
}

char *spell_out_two_digits(int64_t num) {
    char *result = malloc(50 * sizeof(char));
    if (num < 0 || num >= 100) {
        strcpy(result, "Number out of range");
        return result;
    }

    if (num < 10) strcpy(result, units[num]);
    else if (num < 20) strcpy(result, teens[num - 10]);
    else {
        int unit = num % 10, ten = num / 10;
        if (unit == 0) strcpy(result, tens[ten]);
        else sprintf(result, "%s-%s", tens[ten], units[unit]);
    }
    return result;
}

char *spell_out_three_digits(int64_t num) {
    char *result = malloc(100 * sizeof(char));
    if (num < 100) {
        char *two_digit_result = spell_out_two_digits(num);
        strcpy(result, two_digit_result);
        free(two_digit_result);
    } else {
        int hundred = num / 100, remainder = num % 100;
        if (remainder == 0) sprintf(result, "%s hundred", units[hundred]);
        else {
            char *two_digit_result = spell_out_two_digits(remainder);
            sprintf(result, "%s hundred %s", units[hundred], two_digit_result);
            free(two_digit_result);
        }
    }
    return result;
}

char *spell_out_number(int64_t num) {
    if (num == 0) return strdup("zero");
    char *result = malloc(1000 * sizeof(char));
    result[0] = '\0';
    int64_t chunks[4];
    int chunk_count = 0;

    while (num > 0) {
        chunks[chunk_count++] = num % 1000;
        num /= 1000;
    }

    for (int i = chunk_count - 1; i >= 0; i--) {
        if (chunks[i] > 0) {
            char *chunk_str = spell_out_three_digits(chunks[i]);
            if (result[0] != '\0') strcat(result, " ");
            strcat(result, chunk_str);
            if (i > 0) {
                strcat(result, " ");
                strcat(result, thousands[i]);
            }
            free(chunk_str);
        }
    }

    return result;
}

int say(int64_t input, char **ans) {
    if (input < 0 || input > 999999999999) {
        *ans = strdup("Number out of range");
        return -1;
    }
    *ans = spell_out_number(input);
    return 0;
}
