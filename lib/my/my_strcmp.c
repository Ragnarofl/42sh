/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != 0 || s2[i] != 0; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
