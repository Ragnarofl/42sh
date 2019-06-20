/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** echo_error
*/

#include "include/mini.h"

int close_par(char **arr, tofree_t *tofree)
{
    (void)tofree;

    int nb = my_count_char(arr, ')');

    if (nb == 0)
        return (0);
    else {
        my_dprintf(2, "Too many )'s.\n");
        return (1);
    }
    return (0);
}

int open_par(char **arr, tofree_t *tofree)
{
    (void)tofree;

    int nb = my_count_char(arr, '(');

    if (nb == 0)
        return (0);
    else {
        my_dprintf(2, "Too many ('s.\n");
        return (1);
    }
    return (0);
}

int simple_quote(char **arr, tofree_t *tofree)
{
    (void)tofree;

    int nb = my_count_char(arr, 39);

    if (nb % 2 == 0)
        return (0);
    else {
        my_dprintf(2, "Unmatched '%c'.\n", 39);
        return (1);
    }
    return (0);
}

int db_quote(char **arr, tofree_t *tofree)
{
    (void)tofree;

    int nb = my_count_char(arr, 34);

    if (nb % 2 == 0)
        return (0);
    else {
        my_dprintf(2, "Unmatched '%c'.\n", 34);
        return (1);
    }
    return (0);
}
