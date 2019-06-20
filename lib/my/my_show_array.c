/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_show_word_array
*/

void my_putstr(char const *str);

void my_putchar(char c);

void my_show_array(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
