/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int res = nb;

    if (p < 0) {
        return (0);
    } else if (p == 0) {
        return (1);
    } else {
        res = nb * my_compute_power_rec(nb, p - 1);
    }
    return (res);
}
