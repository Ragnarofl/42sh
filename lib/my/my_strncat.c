/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_strncat
*/

int my_strlen(char const *str);

void *my_calloc(int nb, int size);

char *my_strncat(char *str, char *str1, int nb)
{
    char *dest = my_calloc(my_strlen(str) + nb, 1);

    for (int i = 0; str[i] != 0; i++)
        dest[i] = str[i];
    for (int i = 0, j = my_strlen(str), k = 0; k < nb; i++, k++, j++)
        dest[j] = str1[i];
    return (dest);
}
