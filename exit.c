/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** exit.c
*/

#include "include/mini.h"

void exit_shell(char **arr, tofree_t *tofree, int *fd)
{
    (void)fd;
    int ex = (arr[1] == NULL) ? 0 : my_getnbr(arr[1]) % 256;

    if (my_dbstarlen(arr) > 2) {
        my_dprintf(2, "exit: Expression Syntax.\n");
        return;
    }
    if (arr[1] != NULL && my_isnum(arr[1]) == 0) {
        my_dprintf(2, "exit: Expression Syntax.\n");
        return;
    }
    my_free_tree(tofree->tree);
    my_free_all(tofree);
    if (isatty(0) != 0)
        my_printf("exit\n");
    exit(ex);
}

void reset_buff(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = 0;
}
