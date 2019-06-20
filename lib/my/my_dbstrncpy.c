/*
** EPITECH PROJECT, 2019
** paolo libmy
** File description:
** my_dbstrncpy
*/

#include <stdlib.h>

void *my_calloc(int nb, int size);

int my_strlen(char *str);

int my_dbstarlen(char **arr);

void my_strcpy(char *dest, char *src);

char **my_dbstrncpy(char **arr, int nb)
{
    char **copy = my_calloc(my_dbstarlen(arr), 8);
    char *str = NULL;

    for (int i = 0; arr[i] && i < nb; i++) {
        str = my_calloc(my_strlen(arr[i]), 1);
        my_strcpy(str, arr[i]);
        copy[i] = str;
    }
    return (copy);
}
