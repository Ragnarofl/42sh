/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** manage_semicolon
*/

#include "include/mini.h"

void handle_semicolon(tree_t *tree, tofree_t *tofree, int read, int write)
{
    analyse_tree(tree->left, tofree, read, write);
    analyse_tree(tree->right, tofree, read, write);
}

void handle_simpleright(tree_t *tree, tofree_t *tofree, int read, int write)
{
    (void)write;
    tofree->and = 0;
    int fd = open(tree->right->data[0], O_TRUNC | O_WRONLY | \
    O_CREAT, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

    analyse_tree(tree->left, tofree, read, fd);
    close(fd);
}

void handle_doubleright(tree_t *tree, tofree_t *tofree, int read, int write)
{
    (void)write;
    tofree->and = 0;
    int fd = open(tree->right->data[0], O_APPEND | O_WRONLY | \
    O_CREAT, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

    analyse_tree(tree->left, tofree, read, fd);
    close(fd);
}

void handle_simpleleft(tree_t *tree, tofree_t *tofree, int read, int write)
{
    (void)read;
    int fd = open(tree->right->data[0], O_RDONLY);

    tofree->and = 0;
    if (fd == -1) {
        my_dprintf(2, "%s: No such file or directory.\n", tree->right->data[0]);
        return;
    }
    analyse_tree(tree->left, tofree, fd, write);
}

void handle_parenthese(tree_t *tree, tofree_t *tofree, int read, int write)
{
    (void)tree;
    (void)tofree;
    (void)read;
    (void)write;
}
