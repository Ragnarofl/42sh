/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_strncpy
*/

int my_strlen(char *str);

void my_strncpy(char *dest, char *src, int nb)
{
    for (int i = 0; src[i] != 0 && nb > 0; i++, nb--)
        dest[i] = src[i];
}
