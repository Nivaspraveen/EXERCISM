#include "list_ops.h"
#include <stdlib.h>
#include <string.h>

list_t *new_list(size_t length, list_element_t elements[]) {
    list_t *list = malloc(sizeof(*list) + length * sizeof(list_element_t));   
    if (!list) return NULL;
    list->length = length;
    for (size_t i = 0; i < length; ++i) list->elements[i] = elements[i];
    return list;
}

list_t *append_list(list_t *list1, list_t *list2) {
    list_element_t* elements = malloc((length_list(list1) + length_list(list2)) * sizeof(list_element_t));
    size_t i, j;
    for (i = 0; i < list1->length; ++i) elements[i] = list1->elements[i];
    for (j = 0; j < list2->length; ++j, ++i) elements[i] = list2->elements[j];
    list_t *list = new_list(list1->length + list2->length, elements);
    free(elements);
    return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    size_t length = 0;
    list_element_t* elements = malloc(length_list(list) * sizeof(list_element_t));
    for (size_t i = 0; i < length_list(list); ++i) {
        if (filter(list->elements[i])) elements[length++] = list->elements[i];
    }
    list_t *filtered = new_list(length, elements);
    free(elements);
    return filtered;
}

size_t length_list(list_t *list) {
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    list_t *transformed = new_list(length_list(list), list->elements);
    if (!transformed) return NULL;
    for (size_t i = 0; i < length_list(list); ++i) transformed->elements[i] = map(list->elements[i]);
    return transformed;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    list_element_t accumulator = initial;
    for (size_t i = 0; i < list->length; ++i) accumulator = foldl(list->elements[i], accumulator);
    return accumulator;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    list_element_t accumulator = initial;
    for (size_t i = 0; i < list->length; ++i) accumulator = foldr(list->elements[list->length - 1 - i], accumulator);
    return accumulator;
}

list_t *reverse_list(list_t *list) {
    if (!list) return NULL;
    list_t *reversed = new_list(list->length, list->elements);
    if (!reversed) return NULL;
    for (size_t i = 0; i < list->length; ++i) reversed->elements[i] = list->elements[list->length - i - 1];
    return reversed;
}

void delete_list(list_t *list) {
    free(list);
}