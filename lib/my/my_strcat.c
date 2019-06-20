/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

void *my_calloc(int nb, int size);

char *my_strcat(char *s1, char *s2, int tofree)
{
    char *dest = my_calloc(my_strlen(s1) + my_strlen(s2), 1);

    for (int i = 0; s1[i] != 0; i++)
        dest[i] = s1[i];
    for (int i = 0, j = my_strlen(s1); s2[i] != 0; i++, j++)
        dest[j] = s2[i];
    switch (tofree) {
        case (1):
        free(s1);
        break;
        case (2):
        free(s2);
        break;
        case (3):
        free(s1);
        free(s2);
    }
    return (dest);
}
