#include "pythagorean_triplet.h"
#include <stdbool.h>

triplets_t *triplets_with_sum(uint16_t sum)
{
    triplets_t *result = (triplets_t *)malloc(sizeof(triplets_t));
    result->count = 0;
    result->triplets = NULL;
    for (uint16_t a = 1; a < sum / 3; a++)
    {
        for (uint16_t b = a + 1; b < sum / 2; b++)
        {
            uint16_t c = sum - a - b;
            if (a * a + b * b == c * c)
            {
                result->count++;
                result->triplets = (triplet_t *)realloc(result->triplets, result->count * sizeof(triplet_t));
                result->triplets[result->count - 1].a = a;
                result->triplets[result->count - 1].b = b;
                result->triplets[result->count - 1].c = c;
            }
        }
    }
    return result;
}

void free_triplets(triplets_t *triplets)
{
    if (triplets != NULL)
    {
        free(triplets->triplets);
        free(triplets);
    }
}