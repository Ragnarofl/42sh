/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_getnbr
*/

long my_getnbr(char *str)
{
    int i = 0;
    int a = 1;
    long res = 0;

    for (; str[i] == '-' || str[i] == '+'; i++)
        a = (str[i] == '-') ? a * -1 : a;
    for (; str[i] > 47 && str[i] < 58; i++)
        res = res * 10 + (str[i] - 48);
    return (a * res);
}
