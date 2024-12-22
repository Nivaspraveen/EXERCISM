#include "prime_factors.h"
#include <stdint.h>
#include <stddef.h>

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    size_t count = 0;
    uint64_t divisor = 2;
    while (n > 1 && count < MAXFACTORS)
    {
        while (n % divisor == 0)
        {
            factors[count++] = divisor;
            n /= divisor;
            if (count >= MAXFACTORS)
                return count;
        }
        divisor++;
        if (divisor * divisor > n && n > 1)
        {
            factors[count++] = n;
            break;
        }
    }
    return count;
}