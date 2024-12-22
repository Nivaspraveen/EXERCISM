#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate)
{
    int original_candidate = candidate, num_digits = 0;
    while (candidate > 0)
    {
        candidate /= 10;
        num_digits++;
    }
    candidate = original_candidate;
    int sum_of_powers = 0;
    while (candidate > 0)
    {
        int digit = candidate % 10;
        sum_of_powers += (int)pow(digit, num_digits);
        candidate /= 10;
    }
    return sum_of_powers == original_candidate;
}