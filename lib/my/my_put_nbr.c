/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_put_nbr
*/

void my_putstr(char const *str, int fd);

void my_putchar(char c, int fd);

int my_put_nbr(int nb, int fd)
{
    if (nb == -2147483648) {
        my_putstr("-2", fd);
        nb = 147483648;
    }
    if (nb < 0) {
        my_putchar('-', fd);
        nb *= -1;
    }
    if (nb < 10) {
        my_putchar(nb + 48, fd);
        return (nb);
    } else {
        my_putchar(nb - my_put_nbr(nb / 10, fd) * 10 + 48, fd);
        return (nb);
    }
    return (0);
}
