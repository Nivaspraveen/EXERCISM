#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int n)
{
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= n; i++)
        sum += i * i;
    return sum;
}

unsigned int square_of_sum(unsigned int n)
{
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= n; i++)
        sum += i;
    return sum * sum;
}

unsigned int difference_of_squares(unsigned int n)
{
    return square_of_sum(n) - sum_of_squares(n);
}