#include "gigasecond.h"
#include <stdio.h>

void gigasecond(time_t input, char *output, size_t size)
{
    time_t gigasecond_later = input + 1000000000;
    struct tm *utc_time = gmtime(&gigasecond_later);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", utc_time);
}