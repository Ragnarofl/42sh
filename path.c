/*
** EPITECH PROJECT, 2019
** path
** File description:
** path
*/

#include "include/mini.h"

char *copy_var(char *str, char *stock, int i, int len)
{
    char *new = my_calloc(my_strlen(str) + my_strlen(stock) - len, 1);
    int k = i;

    my_strncpy(new, str, i);
    for (int j = 0; stock[j]; j++, k++)
        new[k] = stock[j];
    my_strcpy(new + k, str + i + len + 1);
    free(str);
    free(stock);
    return (new);
}

int check_var_env(char *str, tofree_t *tofree, char **stock, int *len)
{
    for (env_t *ex = tofree->first; ex; ex = ex->next) {
        if (my_strncmp(ex->name, str, my_strlen(ex->name)) == 0 && \
        my_char_is_present(str[my_strlen(ex->name)], " \n\t") == 1) {
            *len = my_strlen(ex->name) + 1;
            *stock = my_calloc(my_strlen(ex->value), 1);
            my_strcpy(*stock, ex->value);
            return (1);
        }
    }
    *stock = my_calloc(255, 1);
    for (int i = 0; my_char_is_present(str[i], " \t\n") == 0; i++)
        (*stock)[i] = str[i];
    my_dprintf(2, "%s: Undefined variable.\n", *stock);
    free(*stock);
    return (0);
}

char *replace_var_env(char *str, tofree_t *tofree)
{
    char *stock = NULL;
    int i = 0;
    int len = 0;

    for (; str[i]; i++) {
        if (str[i] == '$' && check_var_env(str + i + 1, tofree, &stock, \
        &len) == 1)
            str = copy_var(str, stock, i, len);
        else if (str[i] == '$') {
            free(str);
            return (NULL);
        }
    }
    return (str);
}
