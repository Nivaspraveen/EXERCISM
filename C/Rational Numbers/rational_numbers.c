#include "rational_numbers.h"
#include <stdlib.h>
#include <math.h>

static int16_t gcd(int16_t a, int16_t b)
{
    while (b != 0)
    {
        int16_t t = b;
        b = a % b;
        a = t;
    }
    return abs(a);
}

rational_t reduce(rational_t r)
{
    int16_t divisor = gcd(r.numerator, r.denominator);
    r.numerator /= divisor;
    r.denominator /= divisor;
    if (r.denominator < 0)
    {
        r.numerator = -r.numerator;
        r.denominator = -r.denominator;
    }
    return r;
}

rational_t add(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    return reduce(result);
}

rational_t subtract(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    return reduce(result);
}

rational_t multiply(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    return reduce(result);
}

rational_t divide(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r1.denominator * r2.numerator;
    if (result.denominator == 0)
        exit(EXIT_FAILURE);
    return reduce(result);
}

rational_t absolute(rational_t r)
{
    r.numerator = abs(r.numerator);
    r.denominator = abs(r.denominator);
    return reduce(r);
}

rational_t exp_rational(rational_t r, int16_t n)
{
    if (n == 0)
        return (rational_t){1, 1};
    rational_t result;
    if (n > 0)
    {
        result.numerator = pow(r.numerator, n);
        result.denominator = pow(r.denominator, n);
    }
    else
    {
        n = -n;
        result.numerator = pow(r.denominator, n);
        result.denominator = pow(r.numerator, n);
    }
    return reduce(result);
}

float exp_real(uint16_t x, rational_t r)
{
    float base = pow(x, r.numerator);
    return pow(base, 1.0 / r.denominator);
}