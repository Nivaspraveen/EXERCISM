#include "knapsack.h"
#include <stddef.h>
#include <stdlib.h>

unsigned int maximum_value(unsigned int max_weight, const item_t *items, size_t item_count)
{
    unsigned int *dp = (unsigned int *)calloc(max_weight + 1, sizeof(unsigned int));
    for (size_t i = 0; i < item_count; i++)
    {
        for (int w = max_weight; w >= (int)items[i].weight; w--)
        {
            unsigned int new_value = dp[w - items[i].weight] + items[i].value;
            if (new_value > dp[w])
                dp[w] = new_value;
        }
    }
    unsigned int result = dp[max_weight];
    free(dp);
    return result;
}