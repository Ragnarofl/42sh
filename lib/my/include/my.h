/*
** EPITECH PROJECT, 2019
** libmy paolo reant
** File description:
** my.h
*/

#ifndef __MY__
#define __MY__
#include "printf.h"
#include "plus.h"

int my_nbrlen(long int nb, int base);
char **my_dbstrncpy(char **arr, int nb);
int my_isnum(char *str);
int my_isalpha(char *str);
void *my_calloc(int nb, int size);
char *my_char_nbr(int nb);
int my_char_is_present(char c, char *str);
int my_str_is_present(char *str, char *comparator);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_dbstarlen(char **arr);
char **my_dbstrcpy(char **arr);
void my_free_array(char **arr);
long my_getnbr_gap(char *str, int i);
long my_getnbr(char *str);
int my_printf(char *str, ...);
int my_dprintf(int fd, char *str, ...);
int my_put_nbr(int nb, int fd);
void my_putchar(char c, int fd);
long int my_putnbr_base(long int nb, char *base, char m, int fd);
void my_putstr(char const *str, int fd);
int my_rand_nbr(int a, int b);
char *my_reallocarr(char *str, int nb);
char *my_revstr(char *str);
void my_sort_int_array(int *array, int size);
char **my_str_to_word_array(char *str, char *separator);
char *my_strdup(char *str);
int my_strlen(char const *str);
char *my_strncat(char *str, char *str1, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_strncpy(char *dest, char *src, int nb);
int check_tofind(char *str, char *to_find, int i);
char *my_strcat(char *s1, char *s2, int tofree);
int my_strcmp(char *s1, char *s2);
void my_strcpy(char *dest, char *src);

#endif /* __MY__ */
