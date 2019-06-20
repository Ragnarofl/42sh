/*
** EPITECH PROJECT, 2019
** libmy paolo reant
** File description:
** my_dbcreate
*/

void *my_calloc(int nb, int size);

char **my_dbcreate(int y, int x)
{
    char **arr = my_calloc(y, 8);

    for (int i = 0; i < y; i++)
        arr[i] = my_calloc(x, 1);
    return (arr);
}
