/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** exec_prog2.c
*/

#include "include/mini.h"

static const builtin_t str[] = {
    {"cd", &make_cd},
    {"exit", &exit_shell},
    {"setenv", &set_env},
    {"unsetenv", &unset_env},
    {"env", &show_env},
    {"echo", &my_echo},
    {"alias", &create_alias}
};

void close_fd(int *fd)
{
    if (fd[0] > 2)
        close(fd[0]);
    if (fd[1] > 2)
        close(fd[1]);
}

int is_builtin(char **arr, tofree_t *tofree, int read, int write)
{
    for (int i = 0; i < 7; i++) {
        if (my_strcmp(arr[0], str[i].command) == 0) {
            str[i].p(arr, tofree, (int[2]){read, write});
            dup2(0, tofree->stdin);
            dup2(1, tofree->stdout);
            return (1) ;
        }
    }
    return (0);
}

void prepare_exec(tofree_t *tofree, char *pathname, char **arr, int *fd)
{
    if (!fork()) {
        if (fd[0] != 0)
            dup2(fd[0], 0);
        if (fd[1] != 1)
            dup2(fd[1], 1);
        execve(pathname, arr, tofree->env);
        exit(84);
    } else {
        wait(&tofree->statut);
        close_fd(fd);
    }
}
