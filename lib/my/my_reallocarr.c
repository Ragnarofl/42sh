/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_reallocarr
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);

char *my_calloc(int nb, int size);

char *my_reallocarr(char *str, int nb)
{
    char *str1 = my_calloc(nb, 1);

    if (!str1)
        return (NULL);
    my_strcpy(str1, str);
    return (str1);
}
