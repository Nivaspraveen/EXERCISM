#include "square_root.h"
#include <stdint.h>
uint16_t square_root(uint32_t number)
{
    if (number == 0 || number == 1)
        return number;
    uint32_t low = 1, high = number, result = 0;
    while (low <= high)
    {
        uint32_t mid = low + (high - low) / 2;
        if (mid * mid == number)
            return (uint16_t)mid;
        if (mid * mid < number)
        {
            low = mid + 1;
            result = mid;
        }
        else
            high = mid - 1;
    }
    return (uint16_t)result;
}