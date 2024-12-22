#include "sieve.h"
#include <stdbool.h>
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    if (limit < 2 || max_primes == 0)
        return 0;
    bool *is_prime = malloc((limit + 1) * sizeof(bool));
    if (is_prime == NULL)
        return 0;

    for (uint32_t i = 0; i <= limit; i++)
        is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;

    for (uint32_t i = 2; i * i <= limit; i++)
    {
        if (is_prime[i])
        {
            for (uint32_t j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
    uint32_t count = 0;
    for (uint32_t i = 2; i <= limit && count < max_primes; i++)
    {
        if (is_prime[i])
            primes[count++] = i;
    }
    free(is_prime);
    return count;
}