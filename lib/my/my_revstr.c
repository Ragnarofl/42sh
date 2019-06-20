/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_revstr
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char t = 0;

    for (int i = 0; i < my_strlen(str) / 2; i++) {
        t = str[i];
        str[i] = str[my_strlen(str) - 1 - i];
        str[my_strlen(str) - 1 - i] = t;
    }
    return (str);
}
