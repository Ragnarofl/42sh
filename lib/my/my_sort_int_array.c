/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *array, int size)
{
    for (int n = 0, t = 0, m = n; n < size; n++) {
        m = n;
        for (;array[m] > array[m + 1] && m >= 0; m--) {
            t = array[m];
            array[m] = array[m + 1];
            array[m + 1] = t;
        }
    }
}
