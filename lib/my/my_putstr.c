/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_putstr
*/
#include <unistd.h>

void my_putchar(char c, int fd);

void my_putstr(char const *str, int fd)
{
    for (int i = 0; str[i] != 0; i++)
        my_putchar(str[i], fd);
}
