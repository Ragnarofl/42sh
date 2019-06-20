/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** tools.c
*/

#include "include/mini.h"

char *get_name(char *name)
{
    char *new = my_calloc(my_strlen(name), 1);
    int j = 0;

    for (int i = 0; name[i]; i++) {
        j = (name[i] == '/') ? i: j;
    }
    if (name[0] == '/')
        my_strcpy(new, name + j + 1);
    else
        my_strcpy(new, name + j);
    return (new);
}

char *get_direc(char *name)
{
    char *new = my_calloc(my_strlen(name), 1);
    int k = 0;

    for (int i = 0; name[i]; i++)
        k = (name[i] == '/') ? i : k;
    if (k == 0)
        my_strcpy(new, ".");
    else
        my_strncpy(new, name, k);
    return (new);
}

void my_free_tree(tree_t *tree)
{
    if (!tree)
        return;
    my_free_array(tree->data);
    my_free_tree(tree->right);
    my_free_tree(tree->left);
    free(tree);
}

void get_env(tofree_t *tofree)
{
    if (tofree->env != NULL)
        my_free_array(tofree->env);
    int count = 0;
    for (env_t *ex = tofree->first; ex; ex = ex->next, count++);
    tofree->env = my_calloc(count, 8);
    count = 0;
    for (env_t *ex = tofree->first; ex; ex = ex->next, count++) {
        tofree->env[count] = my_calloc(my_strlen(ex->name) + \
        my_strlen(ex->value) + 1, 1);
        my_strcpy(tofree->env[count], ex->name);
        tofree->env[count][my_strlen(ex->name)] = '=';
        my_strcpy(tofree->env[count] + my_strlen(ex->name) + 1, ex->value);
    }
}

void my_free_all(tofree_t *tofree)
{
    for (env_t *ex = tofree->first; ex;) {
        env_t *rid = ex;
        ex = ex->next;
        free(rid->name);
        free(rid->value);
        free(rid);
    }
    if (tofree->env != NULL)
        my_free_array(tofree->env);
    free(tofree->previous);
    free(tofree->name);
    free(tofree->buff);
    free(tofree);
}
