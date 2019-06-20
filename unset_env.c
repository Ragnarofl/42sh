/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** unset_env.c
*/

#include "include/mini.h"

void unsetenv_oldpwd(tofree_t *tofree)
{
    char **arr = my_calloc(2, 8);

    arr[0] = "unsetenv";
    arr[1] = "OLDPWD";
    unset_env(arr, tofree, (int[2]){0, 1});
    free(arr);
}

void create_tmp(tofree_t *tofree)
{
    env_t *tmp = malloc(sizeof(*tmp));

    if (tmp) {
        tmp->name = NULL;
        tmp->value = NULL;
        tmp->next = tofree->first;
        tofree->first = tmp;
    }
}

void del_tmp(tofree_t *tofree)
{
    env_t *rid = tofree->first;

    tofree->first = tofree->first->next;
    free(rid);
}

void delete_var(tofree_t *tofree, char *name)
{
    env_t *back = NULL;
    create_tmp(tofree);
    back = tofree->first;

    for (env_t *ex = tofree->first->next; ex; ex = ex->next) {
        if (my_strcmp(ex->name, name) == 0) {
            back->next = ex->next;
            free(ex->name);
            free(ex->value);
            free(ex);
            del_tmp(tofree);
            return;
        }
        back = back->next;
    }
    del_tmp(tofree);
}

void unset_env(char **arr, tofree_t *tofree, int *fd)
{
    (void)fd;
    if (my_dbstarlen(arr) != 2)
        my_dprintf(2, "invalid number of arguments.\n");
    else
        delete_var(tofree, arr[1]);
}
