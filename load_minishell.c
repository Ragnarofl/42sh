/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** load_minishell
*/

#include "include/mini.h"

static const command_t arr[] = {
    {";", &handle_semicolon},
    {">", &handle_simpleright},
    {">>", &handle_doubleright},
    {"<", &handle_simpleleft},
    {"<<", &handle_doubleleft},
    {"|", &handle_pipe},
    {"||", &handle_double_pipe},
    {"&&", &handle_and},
    {"(", &handle_parenthese}
};

void analyse_tree(tree_t *tree, tofree_t *tofree, int read, int write)
{
    if (!tree)
        return;
    for (int i = 0; i < 8; i++) {
        if (my_strcmp(tree->data[0], arr[i].command) == 0) {
            arr[i].p(tree, tofree, read, write);
            return;
        }
    }
    if (launch_exec(tree->data, tofree, read, write) == 0)
        return;
    my_dprintf(2, "%s: Command not found.\n", tree->data[0]);
}

static void check_buff(tofree_t *tofree)
{
    char **arr = my_str_to_word_array(tofree->buff, " \t\n");

    if (arr == NULL)
        return;
    tofree->tree = create_tree(arr);
    analyse_tree(tofree->tree, tofree, 0, 1);
    my_free_tree(tofree->tree);
}

void get_input(tofree_t *tofree)
{
    char tmp[1] = "\0";

    tofree->buff = my_calloc(0, sizeof(char));
    for (; my_strcmp("\n", tmp) != 0;) {
        if (read(0, tmp, 1) == 0 || tmp[0] == 4) {
            my_free_all(tofree);
            my_printf(isatty(0) ? "exit\n" : "");
            exit(0);
        }
        tofree->buff = my_strcat(tofree->buff, tmp, 1);
    }
}

void load_shell(char **env)
{
    tofree_t *tofree = create_struct(env);
    size_t z = 0;

    unsetenv_oldpwd(tofree);
    for (; 1;) {
        if (isatty(0) != 0) {
            my_printf("\033[1;36m%s$> \033[0m", tofree->name);
            get_input(tofree);
        } else if (getline(&tofree->buff, &z, stdin) == -1 && isatty(0) == 0) {
            my_free_all(tofree);
            my_printf(isatty(0) ? "exit\n" : "");
            exit(0);
        }
        tofree->buff = replace_var_env(tofree->buff, tofree);
        if (tofree->buff) {
            check_buff(tofree);
            reset_buff(tofree->buff);
        }
    }
}
