/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** echo2
*/

#include "include/mini.h"

char *my_char_cat(char c, char d)
{
    char *str = my_calloc(2, 1);

    str[0] = c;
    str[1] = d;
    return (str);
}

char *supp_char2(char *str, char *str2)
{
    int j = 0;
    char *str3 = my_char_cat(39, 34);

    str = my_calloc(my_strlen(str2), 1);
    for (int i = 0; str2[i] != 0;) {
        if (my_char_is_present(str2[i], str3) == 1) {
            i++;
        } else {
            str[j] = str2[i];
            i++;
            j++;
        }
    }
    free(str3);
    return (str);
}

char **supp_char(char **arr, char **array)
{
    array = my_calloc(my_dbstarlen(arr), 8);
    for (int i = 1; arr[i]; i++)
        array[i] = supp_char2(array[i], arr[i]);
    return (array);
}
