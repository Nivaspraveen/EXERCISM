#include "linked_list.h"
#include <stdlib.h>

static struct list_node* create_node(ll_data_t data) {
    struct list_node *node = (struct list_node*)malloc(sizeof(struct list_node));
    if (node == NULL) return NULL;
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

struct list *list_create(void) {
    struct list *list = (struct list*)malloc(sizeof(struct list));
    if (list == NULL) return NULL;
    list->first = list->last = NULL;
    return list;
}

size_t list_count(const struct list *list) {
    size_t count = 0;
    struct list_node *curr = list->first;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

void list_push(struct list *list, ll_data_t item_data) {
    struct list_node *node = create_node(item_data);
    if (node == NULL) return;
    if (list->last == NULL) list->first = list->last = node;
    else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
}

ll_data_t list_pop(struct list *list) {
    if (list->last == NULL) return -1;
    struct list_node *node = list->last;
    ll_data_t data = node->data;
    list->last = node->prev;
    if (list->last != NULL) list->last->next = NULL;
    else list->first = NULL;
    free(node);
    return data;
}

void list_unshift(struct list *list, ll_data_t item_data) {
    struct list_node *node = create_node(item_data);
    if (node == NULL) return;
    if (list->first == NULL) list->first = list->last = node;
    else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }
}

ll_data_t list_shift(struct list *list) {
    if (list->first == NULL) return -1;
    struct list_node *node = list->first;
    ll_data_t data = node->data;
    list->first = node->next;
    if (list->first != NULL) list->first->prev = NULL;
    else list->last = NULL;
    free(node);
    return data;
}

void list_delete(struct list *list, ll_data_t data) {
    struct list_node *curr = list->first;
    while (curr != NULL) {
        if (curr->data == data) {
            if (curr->prev != NULL) curr->prev->next = curr->next;
            else list->first = curr->next;
            if (curr->next != NULL) curr->next->prev = curr->prev;
            else list->last = curr->prev;
            free(curr);
            return;
        }
        curr = curr->next;
    }
}

void list_destroy(struct list *list) {
    struct list_node *curr = list->first;
    while (curr != NULL) {
        struct list_node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}