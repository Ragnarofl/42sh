/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_char_is_present.c
*/

int my_nchar_is_present(char c, char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == c)
            return (i + 1);
    }
    return (0);
}
