/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_strstr
*/

#include <unistd.h>

int check_tofind(char *str, char *to_find, int i)
{
    for (int j = i, k = 0; str[j] == to_find[k]; j++, k++) {
        if (to_find[k + 1] == 0)
            return (1);
    }
    return (0);
}

char *my_strstr(char *str, char *to_find)
{
    for (int i = 0; str[i] != 0; i++) {
        if (check_tofind(str, to_find, i) != 0)
            return (str + i);
    }
    return (NULL);
}
