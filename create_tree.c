/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** create_tree.c
*/

#include "include/mini.h"

tree_t *create_node(char **arr)
{
    tree_t *tree = malloc(sizeof(*tree));

    if (tree) {
        tree->data = arr;
        tree->right = NULL,
        tree->left = NULL;
    }
    return (tree);
}

char **get_arr_right(char **arr, char *op)
{
    char **right = NULL;
    int index = 0;

    for (; arr[index]; index++) {
        if (my_strcmp(arr[index], op) == 0) {
            right = my_dbstrcpy(arr + index + 1);
            break;
        }
    }
    my_free_array(arr);
    return (right);
}

char **get_arr_left(char **arr, char *op)
{
    char **left = NULL;
    int index = 0;

    for (; arr[index]; index++) {
        if (my_strcmp(arr[index], op) == 0) {
            left = my_dbstrncpy(arr, index);
            break;
        }
    }
    return (left);
}

void fill_tree(tree_t *node)
{
    char *op = NULL;

    if ((op = find_op(node->data))) {
        node->left = create_node(get_arr_left(node->data, op));
        node->right = create_node(get_arr_right(node->data, op));
        node->data = get_op(op);
        fill_tree(node->left);
        fill_tree(node->right);
    } else {
        node->right = NULL;
        node->left = NULL;
    }
}

tree_t *create_tree(char **arr)
{
    tree_t *tree = malloc(sizeof(*tree));

    if (tree) {
        tree->right = NULL;
        tree->left = NULL;
        tree->data = arr;
        fill_tree(tree);
    }
    return (tree);
}
