#include "nth_prime.h"

bool is_prime(uint32_t num)
{
    if (num <= 1)
        return false;
    if (num <= 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (uint32_t i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

uint32_t nth(uint32_t n)
{
    if (n == 0)
        return 0;
    uint32_t count = 0, num = 1;
    while (count < n)
    {
        num++;
        if (is_prime(num))
            count++;
    }
    return num;
}