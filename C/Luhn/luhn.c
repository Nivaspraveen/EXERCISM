#include "luhn.h"
#include <ctype.h>
#include <string.h>

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int luhn_checksum(const char *num)
{
    int sum = 0, len = strlen(num), digit_count = 0;
    bool alternate = false;
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == ' ')
            continue;
        if (!is_digit(num[i]))
            return -1;
        int n = num[i] - '0';
        digit_count++;
        if (alternate)
        {
            n *= 2;
            if (n > 9)
                n -= 9;
        }
        sum += n;
        alternate = !alternate;
    }
    if (digit_count <= 1)
        return -1;
    return sum;
}

bool luhn(const char *num)
{
    int checksum = luhn_checksum(num);
    if (checksum == -1)
        return false;
    return (checksum % 10) == 0;
}