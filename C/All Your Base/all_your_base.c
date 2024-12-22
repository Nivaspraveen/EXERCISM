#include "all_your_base.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Helper function to validate input digits and base
static bool is_valid_input(const int8_t digits[], size_t length, int16_t base)
{
    if (base <= 1)
        return false;
    for (size_t i = 0; i < length; ++i)
    {
        if (digits[i] < 0 || digits[i] >= base)
            return false;
    }
    return true;
}

// Helper function to convert from input base to base 10
static uint64_t to_base_10(const int8_t digits[], size_t length, int16_t base)
{
    uint64_t value = 0;
    for (size_t i = 0; i < length; ++i)
        value = value * base + digits[i];
    return value;
}

// Helper function to convert from base 10 to output base
static size_t from_base_10(uint64_t value, int16_t base, int8_t output[DIGITS_ARRAY_SIZE])
{
    size_t index = 0;
    do
    {
        output[index++] = value % base;
        value /= base;
    } while (value > 0 && index < DIGITS_ARRAY_SIZE);
    for (size_t i = 0; i < index / 2; ++i)
    {
        int8_t temp = output[i];
        output[i] = output[index - i - 1];
        output[index - i - 1] = temp;
    }
    return index;
}

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length)
{
    if (!is_valid_input(digits, input_length, input_base) || output_base <= 1)
        return 0;
    if (input_length == 0)
        return 0;
    uint64_t value_in_base_10 = to_base_10(digits, input_length, input_base);
    return from_base_10(value_in_base_10, output_base, digits);
}
