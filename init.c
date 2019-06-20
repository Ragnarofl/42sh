/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** init.c
*/

#include "include/mini.h"

void init_term(tofree_t *tofree)
{
    struct termios term;
    struct termios oterm;

    tcgetattr(0, &oterm);
    memcpy(&term, &oterm, sizeof(term));
    term.c_lflag &= ~(ICANON | ECHO);
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &term);
    get_input(tofree);
    tcsetattr(0, TCSANOW, &oterm);
}

tofree_t *create_struct(char **env)
{
    tofree_t *tofree = malloc(sizeof(*tofree));

    if (!tofree) {
        my_dprintf(2, "A memory error occured.\n");
        exit(84);
    }
    tofree->buff = NULL;
    tofree->tree = NULL;
    tofree->alias = NULL;
    tofree->first = NULL;
    tofree->name = my_calloc(500, 1);
    tofree->previous = my_calloc(255, 1);
    tofree->env = NULL;
    tofree->statut = 0;
    tofree->and = 0;
    getcwd(tofree->name, 255);
    create_env(tofree, env);
    return (tofree);
}
