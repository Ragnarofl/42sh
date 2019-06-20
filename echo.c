/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** echo
*/

#include "include/mini.h"

int my_count_char(char **arr, char c)
{
    int nb = 0;

    for (int i = 0; arr[i]; i++) {
        for (int j = 0; arr[i][j] != 0; j++)
            nb += (arr[i][j] == c) ? 1 : 0;
    }
    return (nb);
}

int check_err(char **arr, tofree_t *tofree)
{
    if (simple_quote(arr, tofree) == 1)
        return (1);
    if (open_par(arr, tofree) == 1)
        return (1);
    if (close_par(arr, tofree) == 1)
        return (1);
    if (db_quote(arr, tofree) == 1)
        return (1);
    return (0);
}

void make_echo(char **arr, tofree_t *tofree)
{
    char **array = NULL;
    (void)tofree;

    array = supp_char(arr, array);
    for (int i = 1; array[i]; i++) {
        if (array[i + 1] == NULL)
            my_printf("%s\n", array[i]);
        else
            my_printf("%s ", array[i]);
    }
    my_free_array(array);
}

void my_echo(char **arr, tofree_t *tofree, int *fd)
{
    int status = 0;

    if (check_err(arr, tofree) == 1)
        return;
    if (!fork()) {
        if (fd[0] != 0)
            dup2(fd[0], 0);
        if (fd[1] != 1)
            dup2(fd[1], 1);
        make_echo(arr, tofree);
        exit(0);
    } else {
        wait(&status);
        handle_end_fork(status);
        close_fd(fd);
    }
}
