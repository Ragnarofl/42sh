/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** manage_separator_tools.c
*/

#include "include/mini.h"

char *get_cat(char *buff, tree_t *tree)
{
    char *all = my_calloc(0, 1);
    size_t zero = 0;

    for (; 1;) {
        if (isatty(0) != 0)
            my_printf("? ");
        if (getline(&buff, &zero, stdin) == -1)
            break;
        if (compare_string(tree, buff) == 0)
            break;
        all = my_strcat(all, buff, 1);
    }
    return (all);
}
