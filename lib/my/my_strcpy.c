/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_strcpy
*/

void my_strcpy(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
}
