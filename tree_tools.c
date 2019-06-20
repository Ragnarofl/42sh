/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** tree_tools
*/

#include "include/mini.h"

int check_op(char **arr)
{
    char *op[] = {";", ">", ">>", "<<", "<", "&&", "||", "|", NULL};

    for (int i = 0, j = 0; op[i]; j++) {
        if (arr[j] && my_strcmp(arr[j], op[i]) == 0)
            return (0);
        if (arr[j] == NULL) {
            j = -1;
            i++;
        }
    }
    return (1);
}

char *find_op(char **arr)
{
    char *op[] = {";", ">", ">>", "<<", "<", "&&", "||", "|", "(", ")", NULL};

    for (int i = 0, j = 0; op[i]; j++) {
        if (arr[j] && my_strcmp(arr[j], op[i]) == 0)
            return (op[i]);
        if (arr[j] == NULL) {
            j = -1;
            i++;
        }
    }
    return (NULL);
}

char **get_op(char *op)
{
    char **arr = my_calloc(1, 8);

    arr[0] = my_calloc(my_strlen(op), 1);
    my_strcpy(arr[0], op);
    return (arr);
}

void my_print_tree(tree_t *tree)
{
    if (!tree)
        return;
    for (int i = 0; tree->data[i]; i++)
        my_printf("%s ", tree->data[i]);
    my_printf("\n");
    my_print_tree(tree->left);
    my_print_tree(tree->right);
}
