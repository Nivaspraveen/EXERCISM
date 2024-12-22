#include "sum_of_multiples.h"
#include <stdbool.h>
#include <stdlib.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
    bool *is_multiple = calloc(limit, sizeof(bool));
    unsigned int total_sum = 0;

    for (size_t i = 0; i < number_of_factors; i++)
    {
        unsigned int factor = factors[i];
        if (factor == 0)
            continue;
        for (unsigned int multiple = factor; multiple < limit; multiple += factor)
        {
            if (!is_multiple[multiple])
            {
                is_multiple[multiple] = true;
                total_sum += multiple;
            }
        }
    }
    free(is_multiple);
    return total_sum;
}
