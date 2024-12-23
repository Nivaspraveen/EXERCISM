#include "atbash_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char atbash_transform(char c)
{
    if (isalpha(c))
        return 'z' - (tolower(c) - 'a');
    return c;
}

char *atbash_encode(const char *input)
{
    int len = strlen(input);
    char *encoded = malloc(len * 2);
    if (!encoded)
        return NULL;

    int enc_idx = 0, grp_count = 0;
    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (isalnum(c))
        {
            if (isalpha(c))
                encoded[enc_idx++] = atbash_transform(c);
            else
                encoded[enc_idx++] = c;
            grp_count++;
            if (grp_count == 5)
            {
                encoded[enc_idx++] = ' ';
                grp_count = 0;
            }
        }
    }
    if (enc_idx > 0 && encoded[enc_idx - 1] == ' ')
        enc_idx--;
    encoded[enc_idx] = '\0';
    return encoded;
}

char *atbash_decode(const char *input)
{
    int len = strlen(input);
    char *decoded = malloc(len * 2);
    if (!decoded)
        return NULL;

    int dec_idx = 0;
    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (isalnum(c))
        {
            if (isalpha(c))
                decoded[dec_idx++] = atbash_transform(c);
            else
                decoded[dec_idx++] = c;
        }
    }
    decoded[dec_idx] = '\0';
    return decoded;
}