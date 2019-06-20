/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main.c
*/

#include "include/mini.h"

void handle_error(int sig)
{
    char *name = my_calloc(255, 1);

    switch (sig) {
        case (11):
        my_printf("Segmentation fault");
        break;
        case (6):
        my_printf("Abort");
        break;
        case (8):
        my_printf("Floating exception");
        break;
        case (2):
        my_printf("\n");
        if (isatty(0) != 0)
            my_printf("\033[1;36m%s$> \033[0m", getcwd(name, 255));
    }
    free(name);
}

int handle_end_fork(int i)
{
    if (!WIFSIGNALED(i))
        return (0);
    else {
        handle_error(WTERMSIG(i));
        if (WCOREDUMP(i))
            my_printf(" (core dumped)\n");
        else
            my_printf("\n");
    }
    return (0);
}

int main(int ac, __attribute__((unused))char **av, char **env)
{
    signal(2, &handle_error);
    signal(6, &handle_error);
    signal(8, &handle_error);
    if (ac != 1) {
        my_dprintf(2, "This program doesn't require any arguments.\n");
        return (84);
    }
    load_shell(env);
    return (0);
}
