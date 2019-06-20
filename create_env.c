/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** create_env.c
*/

#include "include/mini.h"

void cut_data(env_t *new, char *all)
{
    int len = 0;
    for (; all[len] != '='; len++);
    new->name = my_calloc(len, 1);
    my_strncpy(new->name, all, len);
    new->value = my_calloc(my_strlen(all) - (len + 1), 1);
    my_strcpy(new->value, all + (len + 1));
}

void add_env(char *all, tofree_t *tofree)
{
    env_t *new = malloc(sizeof(*new));

    if (!new) {
        my_dprintf(2, "A memory error occured.\n");
        exit(84);
    }
    cut_data(new, all);
    new->next = tofree->first;
    tofree->first = new;
}

void create_env(tofree_t *tofree, char **env)
{
    for (int i = 0; env[i]; i++) {
        add_env(env[i], tofree);
    }
}
