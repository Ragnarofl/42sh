/*
** EPITECH PROJECT, 2019
** paolo reant libmy
** File description:
** my_strdup
*/

void *my_calloc(int nb, int size);

int my_strlen(char *str);

void my_strcpy(char *dest, char *src);

char *my_strdup(char *str)
{
    char *copy = my_calloc(my_strlen(str), 1);

    my_strcpy(copy, str);
    return (copy);
}
