/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    for (;str[i] != 0; i++);
    return (i);
}
