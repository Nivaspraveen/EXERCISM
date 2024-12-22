#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <stdint.h>
#include <stddef.h>

#define DIGITS_ARRAY_SIZE 64

/**
 * Rebase a number represented as an array of digits in a given input base
 * into an output base.
 *
 * @param digits The input digits (modified in place for output digits).
 * @param input_base The base of the input number.
 * @param output_base The base of the output number.
 * @param input_length The number of digits in the input.
 * @return The number of digits in the output, or 0 if input is invalid.
 */
size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length);

#endif