#include "binary_search_tree.h"
#include <stdlib.h>

node_t *create_node(int data);
node_t *insert_node(node_t *root, int data);
void in_order_traversal(node_t *root, int *array, int *index);
void count_nodes(node_t *root, int *count);

node_t *create_node(int data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node_t *insert_node(node_t *root, int data)
{
    if (root == NULL)
        return create_node(data);
    if (data <= root->data)
        root->left = insert_node(root->left, data);
    else
        root->right = insert_node(root->right, data);
    return root;
}

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    node_t *root = NULL;
    for (size_t i = 0; i < tree_data_len; i++)
        root = insert_node(root, tree_data[i]);
    return root;
}

void count_nodes(node_t *root, int *count)
{
    if (root == NULL)
        return;
    count_nodes(root->left, count);
    (*count)++;
    count_nodes(root->right, count);
}

void in_order_traversal(node_t *root, int *array, int *index)
{
    if (root == NULL)
        return;
    in_order_traversal(root->left, array, index);
    array[(*index)++] = root->data;
    in_order_traversal(root->right, array, index);
}

int *sorted_data(node_t *tree)
{
    int tree_size = 0;
    count_nodes(tree, &tree_size);
    int *array = (int *)malloc(tree_size * sizeof(int));
    if (array == NULL)
        return NULL;
    int index = 0;
    in_order_traversal(tree, array, &index);
    return array;
}

void free_tree(node_t *tree)
{
    if (tree == NULL)
        return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}