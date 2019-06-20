/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** terms
*/

#include "include/mini.h"

void analyse_input(char tmp[1], tofree_t *tofree)
{
    int check = 0;
    int ret = setupterm(NULL, STDOUT_FILENO, NULL);
    char *le_cap = tgetstr("le", NULL);
    char *dc_cap = tgetstr("dc", NULL);

    if (ret == 0) {
        if (tmp[0] == 127) {
            tputs(le_cap, 1, putchar);
            tputs(dc_cap, 1, putchar);
            check = 1;
        }
        if (check == 0) {
            write(1, &tmp[0], 1);
            tofree->buff = my_strcat(tofree->buff, tmp, 1);
        }
    }
}
