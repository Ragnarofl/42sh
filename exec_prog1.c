/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec_prog1.c
*/

#include "include/mini.h"

char **find_path(tofree_t *tofree)
{
    char **path = NULL;

    for (env_t *ex = tofree->first; ex; ex = ex->next) {
        if (my_strcmp("PATH", ex->name) == 0) {
            path = my_str_to_word_array(ex->value, ":");
            break;
        }
    }
    return (path);
}

void my_strcatpath(char *path, char *command, char *pathname)
{
    int i = 0;

    for (; path[i]; i++)
        pathname[i] = path[i];
    pathname[i] = '/';
    i++;
    for (int k = 0; command[k] != 0; k++, i++)
        pathname[i] = command[k];
}

int check_path(char *pathname, char **path)
{
    if (path == NULL) {
        free(pathname);
        return (-1);
    }
    return (0);
}

int calc_diff(char *name, char *command)
{
    int total = 0;

    if (my_strlen(name) != my_strlen(command))
        return (0);
    for (int i = 0; name[i]; i++)
        total += (name[i] == command[i]) ? 1 : -1;
    if (total > my_strlen(name) / 4)
        return (1);
    return (0);
}

int check_id(char *path, char *command, char **stock)
{
    struct dirent *dp = NULL;
    DIR *dirp = opendir(path);

    for (; (dp = readdir(dirp));) {
        if (calc_diff(dp->d_name, command) == 1) {
            *stock = my_calloc(my_strlen(dp->d_name), 1);
            my_strcpy(*stock, my_strcat(path, my_strcat("/", dp->d_name, 0), 0));
            return (1);
        }
    }
    return (0);
}

int check_mean(char **path, char **arr, tofree_t *tofree)
{
    (void)tofree;
    char *buf = my_calloc(5, 1);
    char *stock = NULL;

    for (int i = 0; path[i]; i++) {
        if (check_id(path[i], arr[0], &stock) == 1) {
            my_printf("Did you mean %s?[y/n]\n", stock);
            read(0, buf, 2);
            if (buf[0] != 'y')
                return (-1);
            free(arr[0]);
            arr[0] = my_calloc(my_strlen(stock), 1);
            my_strcpy(arr[0], stock);
            return (0);
        }
    }
    return (-1);
}

int check_name(char **arr, tofree_t *tofree, char **pathname)
{
    char **path = find_path(tofree);

    if (access(arr[0], F_OK) != -1) {
        my_strcpy(*pathname, arr[0]);
        my_free_array(path);
        return (0);
    }
    if (check_path(*pathname, path) == -1)
        return (-1);
    for (int i = 0; path[i]; i++) {
        my_strcatpath(path[i], arr[0], *pathname);
        if (access(*pathname, F_OK) != -1) {
            my_free_array(path);
            return (0);
        }
        reset_buff(*pathname);
    }
    if (check_mean(path, arr, tofree) == 0) {
        my_strcpy(*pathname, arr[0]);
        return (0);
    }
    my_free_array(path);
    return (-1);
}

int launch_exec(char **arr, tofree_t *tofree, int read, int write)
{
    char *pathname = NULL;

    get_env(tofree);
    if (is_builtin(arr, tofree, read, write) == 1)
        return (0);
    pathname = my_calloc(255, 1);
    if (check_name(arr, tofree, &pathname) == -1) {
        free(pathname);
        tofree->statut = -1;
        return (-1);
    }
    prepare_exec(tofree, pathname, arr, (int[2]){read, write});
    free(pathname);
    return (handle_end_fork(tofree->statut));
}
