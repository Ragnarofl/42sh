/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** manage_separator2.c
*/

#include "include/mini.h"

int compare_string(tree_t *tree, char *buff)
{
    char *copy = my_strdup(buff);

    for (int i = 0; copy[i]; i++)
        copy[i] = (copy[i] == '\n') ? 0 : copy[i];
    if (my_strcmp(tree->right->data[0], copy) == 0)
        return (0);
    return (-1);
}

void handle_doubleleft(tree_t *tree, tofree_t *tofree, int read, int write)
{
    (void)read;
    int pipefd[2];
    char *buff = NULL;
    char *all = NULL;

    pipe(pipefd);
    tofree->and = 0;
    all = get_cat(buff, tree);
    dprintf(pipefd[1], "%s", all);
    close(pipefd[1]);
    analyse_tree(tree->left, tofree, pipefd[0], write);
    close(pipefd[0]);
}

void handle_pipe(tree_t *tree, tofree_t *tofree, int read, int write)
{
    int pipefd[2];
    int write2 = 1;
    int read2 = 0;

    tofree->and = 0;
    pipe(pipefd);
    write2 = pipefd[1];
    read2 = pipefd[0];
    if (!fork()) {
        close(write2);
        analyse_tree(tree->right, tofree, read2 , write);
        exit(0);
    } else {
        close(read2);
        analyse_tree(tree->left, tofree, read, write2);
    }
    wait(NULL);
}

void handle_double_pipe(tree_t *tree, tofree_t *tofree, int read, int write)
{
    if (tofree->and == 2 || tofree->and == 0)
        analyse_tree(tree->left, tofree, read, write);
    if (!WIFEXITED(tofree->statut) || tofree->statut == -1 || \
    tofree->and == 1) {
        tofree->statut = 0;
        tofree->and = 2;
        analyse_tree(tree->right, tofree, read, write);
    } else {
        tofree->and = 1;
        if (check_op(tree->right->data) == 0)
            analyse_tree(tree->right, tofree, read, write);
    }
    return;
}

void handle_and(tree_t *tree, tofree_t *tofree, int read, int write)
{
    if (tofree->and == 2 || tofree->and == 0)
        analyse_tree(tree->left, tofree, read, write);
    if (((WIFEXITED(tofree->statut) && tofree->and == 0) || \
    (tofree->and == 2 && WIFEXITED(tofree->statut))) && tofree->statut != -1) {
        tofree->and = 2;
        analyse_tree(tree->right, tofree, read, write);
    } else {
        tofree->and = 1;
        if (check_op(tree->right->data) == 0)
            analyse_tree(tree->right, tofree, read, write);
    }
    tofree->statut = 0;
    return;
}
