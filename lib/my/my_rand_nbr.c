/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_rand_nbr.c
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int my_rand_nbr(int a, int b)
{
    return (rand() % (b - a) + a);
}
