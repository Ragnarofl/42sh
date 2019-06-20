/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** setenv.c
*/

#include "include/mini.h"

void change_value(env_t *env, char *value)
{
    free(env->value);
    env->value = my_calloc(my_strlen(value), 1);
    my_strcpy(env->value, value);
}

void add_var(tofree_t *tofree, char *name, char *value)
{
    env_t *new = malloc(sizeof(*new));

    if (new) {
        new->name = my_calloc(my_strlen(name), 1);
        new->value = my_calloc(my_strlen(value), 1);
        my_strcpy(new->name, name);
        my_strcpy(new->value, value);
        new->next = tofree->first;
        tofree->first = new;
    }
}

void check_var(tofree_t *tofree, char *name, char *value)
{
    for (env_t *ex = tofree->first; ex; ex = ex->next) {
        if (my_strcmp(ex->name, name) == 0) {
            change_value(ex, value);
            return;
        }
    }
    add_var(tofree, name, value);
}

int check_error(char **arr)
{
    if (my_char_is_present(arr[1][0], ALPHA) == 0) {
        my_dprintf(2, "setenv: Variable name must begin with a letter.\n");
        return (-1);
    }
    if (my_str_is_present(arr[1], AN) == 0) {
        my_dprintf(2, "setenv: Variable name must contain ");
        my_dprintf(2, "alphanumeric characters.\n");
        return (-1);
    }
    return (0);
}

void set_env(char **arr, tofree_t *tofree, int *fd)
{
    if (my_dbstarlen(arr) == 1) {
        show_env(arr, tofree, fd);
        return;
    }
    if (my_dbstarlen(arr) == 2) {
        if (check_error(arr) == -1)
            return;
        check_var(tofree, arr[1], "");
    } else if (my_dbstarlen(arr) == 3) {
        if (check_error(arr) == -1)
            return;
        check_var(tofree, arr[1], arr[2]);
    } else
        my_dprintf(2, "invalid number of arguments.\n");
}
