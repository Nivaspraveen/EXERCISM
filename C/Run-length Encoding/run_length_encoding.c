#include "run_length_encoding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char *custom_strdup(const char *str)
{
    if (!str)
        return NULL;
    size_t len = strlen(str);
    char *copy = malloc(len + 1);
    if (copy)
        strcpy(copy, str);
    return copy;
}

char *encode(const char *text)
{
    if (!text || strlen(text) == 0)
        return custom_strdup("");
    size_t len = strlen(text);
    char *encoded = malloc(len * 2 + 1);
    if (!encoded)
        return NULL;

    size_t enc_idx = 0, count = 1;
    for (size_t i = 1; i <= len; i++)
    {
        if (text[i] == text[i - 1])
            count++;
        else
        {
            if (count > 1)
                enc_idx += sprintf(encoded + enc_idx, "%zu", count);
            encoded[enc_idx++] = text[i - 1];
            count = 1;
        }
    }
    encoded[enc_idx] = '\0';
    return encoded;
}

char *decode(const char *data)
{
    if (!data || strlen(data) == 0)
        return custom_strdup("");
    size_t len = strlen(data);
    char *decoded = malloc(len * 10 + 1);
    if (!decoded)
        return NULL;

    size_t dec_idx = 0, count = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (isdigit(data[i]))
            count = count * 10 + (data[i] - '0');
        else
        {
            if (count == 0)
                count = 1;
            for (; count > 0; count--)
                decoded[dec_idx++] = data[i];
            count = 0;
        }
    }
    decoded[dec_idx] = '\0';
    return decoded;
}