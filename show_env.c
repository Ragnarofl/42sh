/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** show_env.c
*/

#include "include/mini.h"

void show_env(char **arr, tofree_t *tofree, int *fd)
{
    int status = 0;

    if (my_dbstarlen(arr) != 1) {
        my_dprintf(2, "invalid number of arguments.\n");
        return;
    }
    if (!fork()) {
        if (fd[0] != 0)
            dup2(fd[0], 0);
        if (fd[1] != 1)
            dup2(fd[1], 1);
        for (env_t *new = tofree->first; new; new = new->next)
            my_printf("%s=%s\n", new->name, new->value);
        exit(0);
    } else {
        wait(&status);
        handle_end_fork(status);
        close_fd(fd);
    }
}
