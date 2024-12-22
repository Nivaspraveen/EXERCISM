#include "palindrome_products.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Helper function to check if a number is a palindrome
static int is_palindrome(int num)
{
    int reversed = 0, original = num, digit;
    while (num > 0)
    {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed == original;
}

// Helper function to add a factor pair to the list
static factor_t *add_factor(factor_t *head, int a, int b)
{
    factor_t *new_factor = malloc(sizeof(factor_t));
    if (!new_factor)
        return NULL;
    new_factor->factor_a = a;
    new_factor->factor_b = b;
    new_factor->next = head;
    return new_factor;
}

// Main function to find palindrome products
product_t *get_palindrome_product(int from, int to)
{
    if (from > to)
    {
        product_t *error_product = malloc(sizeof(product_t));
        if (!error_product)
            return NULL;
        snprintf(error_product->error, MAXERR, "invalid input: min is %d and max is %d", from, to);
        error_product->smallest = -1;
        error_product->largest = -1;
        error_product->factors_sm = NULL;
        error_product->factors_lg = NULL;
        return error_product;
    }

    product_t *result = malloc(sizeof(product_t));
    if (!result)
        return NULL;

    result->smallest = -1;
    result->largest = -1;
    result->factors_sm = NULL;
    result->factors_lg = NULL;
    result->error[0] = '\0';

    int palindrome_found = 0;

    for (int i = from; i <= to; i++)
    {
        for (int j = i; j <= to; j++)
        {
            int product = i * j;
            if (is_palindrome(product))
            {
                palindrome_found = 1;

                // Smallest palindrome
                if (result->smallest == -1 || product < result->smallest)
                {
                    result->smallest = product;
                    while (result->factors_sm)
                    {
                        factor_t *temp = result->factors_sm;
                        result->factors_sm = result->factors_sm->next;
                        free(temp);
                    }
                    result->factors_sm = add_factor(NULL, i, j);
                }
                else if (product == result->smallest)
                {
                    result->factors_sm = add_factor(result->factors_sm, i, j);
                }

                // Largest palindrome
                if (result->largest == -1 || product > result->largest)
                {
                    result->largest = product;
                    while (result->factors_lg)
                    {
                        factor_t *temp = result->factors_lg;
                        result->factors_lg = result->factors_lg->next;
                        free(temp);
                    }
                    result->factors_lg = add_factor(NULL, i, j);
                }
                else if (product == result->largest)
                {
                    result->factors_lg = add_factor(result->factors_lg, i, j);
                }
            }
        }
    }

    if (!palindrome_found)
    {
        snprintf(result->error, MAXERR, "no palindrome with factors in the range %d to %d", from, to);
    }

    return result;
}

// Free memory allocated for the product structure
void free_product(product_t *p)
{
    if (!p)
        return;

    while (p->factors_sm)
    {
        factor_t *temp = p->factors_sm;
        p->factors_sm = p->factors_sm->next;
        free(temp);
    }

    while (p->factors_lg)
    {
        factor_t *temp = p->factors_lg;
        p->factors_lg = p->factors_lg->next;
        free(temp);
    }

    free(p);
}
