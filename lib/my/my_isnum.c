/*
** EPITECH PROJECT, 2019
** paolo reant libmy
** File description:
** my_isnum
*/

#include "include/my.h"

int my_isnum(char *str)
{
    if (my_str_is_present(str, "0123456789") == 0)
        return (0);
    return (1);
}
