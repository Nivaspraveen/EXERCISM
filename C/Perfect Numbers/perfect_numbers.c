#include "perfect_numbers.h"

static int aliquot_sum(int num)
{
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    return sum;
}

kind classify_number(int num)
{
    if (num <= 0)
        return ERROR;
    int sum = aliquot_sum(num);

    if (sum == num)
        return PERFECT_NUMBER;
    else if (sum > num)
        return ABUNDANT_NUMBER;
    else
        return DEFICIENT_NUMBER;
}