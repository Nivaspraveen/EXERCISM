#include "largest_series_product.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int64_t largest_series_product(char *digits, size_t span)
{
    if (span == 0)
        return 1;
    size_t length = strlen(digits);
    if (span > length)
        return -1;

    for (size_t i = 0; i < length; i++)
    {
        if (!isdigit(digits[i]))
            return -1;
    }

    int64_t max_product;
    for (size_t i = 0; i <= length - span; i++)
    {
        int64_t product = 1;
        for (size_t j = 0; j < span; j++)
        {
            if (!isdigit(digits[i + j]))
                return -1;
            product *= digits[i + j] - '0';
        }
        if (product > max_product || i == 0)
            max_product = product;
    }
    return max_product;
}