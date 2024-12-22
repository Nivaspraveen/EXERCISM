#include "sublist.h"
#include <stdbool.h>
#include <string.h>

static bool is_sublist(int *a, size_t a_len, int *b, size_t b_len);

static bool is_sublist(int *a, size_t a_len, int *b, size_t b_len)
{
    if (a_len == 0)
        return true;
    if (a_len > b_len)
        return false;
    for (size_t i = 0; i <= b_len - a_len; i++)
    {
        if (memcmp(a, &b[i], a_len * sizeof(int)) == 0)
            return true;
    }
    return false;
}

comparison_result_t check_lists(int *list_to_compare, int *base_list, size_t list_to_compare_element_count, size_t base_list_element_count)
{
    if (list_to_compare_element_count == base_list_element_count && memcmp(list_to_compare, base_list, list_to_compare_element_count * sizeof(int)) == 0)
        return EQUAL;
    if (is_sublist(list_to_compare, list_to_compare_element_count, base_list, base_list_element_count))
        return SUBLIST;
    if (is_sublist(base_list, base_list_element_count, list_to_compare, list_to_compare_element_count))
        return SUPERLIST;
    return UNEQUAL;
}