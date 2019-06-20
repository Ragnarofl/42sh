/*
** EPITECH PROJECT, 2019
** paolo reant libmyu
** File description:
** my_isalpha
*/

#include "include/my.h"

int my_isalpha(char *str)
{
    char comp[505645] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (my_str_is_present(str, comp) == 0)
        return (0);
    return (1);
}
