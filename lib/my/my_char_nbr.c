/*
** EPITECH PROJECT, 2019
** paolo reant libmy
** File description:
** my_char_nbr
*/

#include "include/my.h"
#include <stdlib.h>

int get_len(int nb)
{
    int len = 0;

    for (; nb > 0; nb = nb / 10, len++);
    return (len);
}

char *my_char_nbr(int nb)
{
    int len = get_len(nb);
    char *nbr = my_calloc(len, 1);

    for (int i = 0; i < len; i++, nb = nb / 10)
        nbr[len - i - 1] = nb % 10 + 48;
    return (nbr);
}
