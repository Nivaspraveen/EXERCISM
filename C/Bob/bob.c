#include "bob.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static bool is_yelling(const char *str);
static bool is_question(const char *str);
static bool is_silence(const char *str);

static char *duplicate_string(const char *src)
{
    size_t len = strlen(src) + 1;
    char *dest = malloc(len);
    if (dest)
        strcpy(dest, src);
    return dest;
}

// Helper function to check if a string is all uppercase
static bool is_yelling(const char *str)
{
    bool has_letters = false;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            has_letters = true;
            if (!isupper(str[i]))
                return false;
        }
    }
    return has_letters;
}

// Helper function to check if a string is a question
static bool is_question(const char *str)
{
    size_t len = strlen(str);
    return len > 0 && str[len - 1] == '?';
}

// Helper function to check if a string is silence
static bool is_silence(const char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
            return false;
    }
    return true;
}

char *hey_bob(char *greeting)
{
    char *copy = duplicate_string(greeting);
    if (copy == NULL)
        return "Whatever.";
    char *trimmed = copy;
    while (isspace(*trimmed))
        trimmed++;
    size_t len = strlen(trimmed);
    while (len > 0 && isspace(trimmed[len - 1]))
    {
        trimmed[len - 1] = '\0';
        len--;
    }

    char *response;
    if (is_silence(trimmed))
        response = "Fine. Be that way!";
    else if (is_yelling(trimmed) && is_question(trimmed))
        response = "Calm down, I know what I'm doing!";
    else if (is_yelling(trimmed))
        response = "Whoa, chill out!";
    else if (is_question(trimmed))
        response = "Sure.";
    else
        response = "Whatever.";

    free(copy);
    return response;
}