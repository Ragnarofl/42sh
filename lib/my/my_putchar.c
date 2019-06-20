/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}
