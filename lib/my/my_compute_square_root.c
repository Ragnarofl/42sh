/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int n = 0;

    if (nb < 0)
        return (0);
    else {
        for (; n * n < nb; n++);
        if (n * n == nb)
            return (n);
        else
            return (0);
    }
}
