/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** create_alias.c
*/

#include "include/mini.h"

alias_t *new_alias(char **arr)
{
    alias_t *new = malloc(sizeof(*new));

    new->alias = my_calloc(my_strlen(arr[1]), 1);
    my_strcpy(new->alias, arr[1]);
    new->command = my_calloc(0, 1);
    for (int i = 2; arr[i]; i++)
        new->command = my_strcat(my_strcat(new->command, arr[i], 1), " ", 1);
    return (new);
}

void add_alias(char **arr, tofree_t *tofree)
{
    alias_t *new = new_alias(arr);
    new->next = tofree->alias;
    tofree->alias = new;
}

void print_alias(tofree_t *tofree)
{
    for (alias_t *ex = tofree->alias; ex; ex = ex->next) {
        if (my_char_is_present(' ', ex->command) == 1)
            my_printf("%s\t(%s)\n", ex->alias, ex->command);
        else
            my_printf("%s\t%s\n", ex->alias, ex->command);
    }
}

void create_alias(char **arr, tofree_t *tofree, int *fd)
{
    int status = 0;

    if (!fork()) {
        if (fd[0] != 0)
            dup2(fd[0], 0);
        if (fd[1] != 1)
            dup2(fd[1], 1);
        if (my_dbstarlen(arr) == 1)
            print_alias(tofree);
        else
            add_alias(arr, tofree);
        exit(0);
    } else {
        wait(&status);
        handle_end_fork(status);
        close_fd(fd);
    }
}
