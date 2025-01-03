#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <stddef.h>

typedef struct {
   unsigned int weight;
   unsigned int value;
} item_t;

unsigned int maximum_value(unsigned int max_weight, const item_t *items, size_t item_count);

#endif
