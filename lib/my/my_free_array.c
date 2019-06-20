/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_free_char_dbstar
*/

#include <stdlib.h>

void my_free_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}
