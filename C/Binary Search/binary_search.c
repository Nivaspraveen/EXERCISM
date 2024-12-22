#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    if (length == 0)
        return NULL;
    size_t left = 0, right = length - 1;
    while (left <= right && right < length)
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] == value)
            return &arr[mid];
        else if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return NULL;
}