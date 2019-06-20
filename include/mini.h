/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** mini.h
*/

#ifndef __MINI__
#define __MINI__

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/sysmacros.h>
#include <curses.h>
#include <term.h>
#include <termcap.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <grp.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/my/include/my.h"

typedef struct tree_s
{
    char **data;
    struct tree_s *right;
    struct tree_s *left;
} tree_t;

typedef struct env_s
{
    char *name;
    char *value;
    struct env_s *next;
} env_t;

typedef struct alias_s
{
    char *alias;
    char *command;
    struct alias_s *next;
} alias_t;

typedef struct tofree_s
{
    int stdout;
    int stdin;
    char *buff;
    char *name;
    char *previous;
    char **env;
    env_t *first;
    tree_t *tree;
    alias_t *alias;
    int statut;
    int and;
} tofree_t;

typedef struct command_s
{
    char *command;
    void (*p)(tree_t *tree, tofree_t *tofree, int read, int write);
} command_t;

typedef struct builtin_s
{
    char *command;
    void (*p)(char **arr, tofree_t *tofree, int *fd);
} builtin_t;

#define ALPHA ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
#define AN ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")

/* main.c */
void handle_error(int sig);
int handle_end_fork(int i);

/* load_minishell.c */
void load_shell(char **env);
void get_input(tofree_t *tofree);
void analyse_tree(tree_t *tree, tofree_t *tofree, int read, int write);

/* init.c */
void init_term(tofree_t *tofree);
tofree_t *create_struct(char **env);

/* create_env.c */
void create_env(tofree_t *tofree, char **env);

/* tools.c */
void my_free_tree(tree_t *tree);
void my_free_all(tofree_t *tofree);
void reset_buff(char *str);
void get_env(tofree_t *tofree);
char *get_name(char *name);
char *get_direc(char *name);

/* create_tree.c */
tree_t *create_tree(char **arr);

/* tree_tools.c */
char *find_op(char **arr);
int check_op(char **arr);
char **get_op(char *op);
void my_print_tree(tree_t *tree);

/* exec_prog.c */
int launch_exec(char **arr, tofree_t *tofree, int read, int write);
void prepare_exec(tofree_t *tofree, char *pathname, char **arr, int *fd);
int is_builtin(char **arr, tofree_t *tofree, int read, int write);
void close_fd(int *fd);

void my_show_array(char **arr);

/* manage_separator.c */
void handle_semicolon(tree_t *tree, tofree_t *tofree, int read, int write);
void handle_simpleright(tree_t *tree, tofree_t *tofree, int read, int write);
void handle_doubleright(tree_t *tree, tofree_t *tofree, int read, int write);
void handle_simpleleft(tree_t *tree, tofree_t *tofree, int read, int write);
void handle_doubleleft(tree_t *tree, tofree_t *tofree, int read, int write);
void handle_pipe(tree_t *tree, tofree_t *tofree, int read, int write);
void handle_double_pipe(tree_t *tree, tofree_t *tofree, int read, int write);
void handle_and(tree_t *tree, tofree_t *tofree, int read, int write);
void handle_parenthese(tree_t *tree, tofree_t *tofree, int read, int write);
char *get_cat(char *buff, tree_t *tree);
int compare_string(tree_t *tree, char *buff);

/* make_cd.c */
void make_cd(char **arr, tofree_t *tofree, int *fd);
/* unset_env */
void unset_env(char **arr, tofree_t *tofree, int *fd);
void unsetenv_oldpwd(tofree_t *tofree);
/* set_env */
void set_env(char **arr, tofree_t *tofree, int *fd);
/* show_env.c */
void show_env(char **arr, tofree_t *tofree, int *fd);
void close_fd(int *fd);
/* exit.c */
void exit_shell(char **arr, tofree_t *tofree, int *fd);
/* alias.c */
void create_alias(char **arr, tofree_t *tofree, int *fd);
/* echo.c */
void my_echo(char **arr, tofree_t *tofree, int *fd);
int my_count_char(char **arr, char c);
char **supp_char(char **arr, char **array);
/* echo_error.c */
int open_par(char **arr, tofree_t *tofree);
int simple_quote(char **arr, tofree_t *tofree);
int db_quote(char **arr, tofree_t *tofree);
int close_par(char **arr, tofree_t *tofree);
/* terms.c */
void analyse_input(char tmp[1], tofree_t *tofree);

char *replace_var_env(char *str, tofree_t *tofree);

#endif /* __MINI__ */
