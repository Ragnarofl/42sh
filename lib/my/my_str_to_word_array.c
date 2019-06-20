/*
** EPITECH PROJECT, 2019
** libmy paolo reant
** File description:
** my_str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>

int my_char_is_present(char c, char *str);

void *my_calloc(int nb, int size);

void my_strncpy(char *dest, char *src, int nb);

int find_len(char *str, char *separator)
{
    int len = 1;
    int i = 0;

    for (; my_char_is_present(str[i], separator) == 1 || str[i] == 0; i++)
        if (str[i] == 0)
            return (0);
    for (; str[i]; i++) {
        for (; my_char_is_present(str[i], separator) == 1 && str[i + 1]; i++)
            (my_char_is_present(str[i + 1], separator) == 1) ? len : len++;
    }
    return (len);
}

char **my_str_to_word_array(char *str, char *separator)
{
    int count = find_len(str, separator);
    char **arr = my_calloc(count, 8);
    int k = 0;

    if (count == 0) {
        free(arr);
        return (NULL);
    }
    for (int i = 0, j = 0; i < count; i++) {
        for (; my_char_is_present(str[j], separator) == 1; j++);
        k = j;
        for (; my_char_is_present(str[j], separator) == 0 && str[j] != 0; j++);
        arr[i] = my_calloc(j - k, 1);
        my_strncpy(arr[i], str + k, j - k);
    }
    return (arr);
}
