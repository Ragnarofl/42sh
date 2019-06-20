/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** make_cd.c
*/

#include "include/mini.h"

void modify_pwd(tofree_t *tofree)
{
    char **arr = my_calloc(3, 8);

    arr[0] = "setenv";
    arr[1] = "PWD";
    arr[2] = my_calloc(255, 1);
    my_strcpy(arr[2], tofree->name);
    set_env(arr, tofree, (int[2]){0, 1});
    free(arr[2]);
    free(arr);
}

void modify_oldpwd(tofree_t *tofree)
{
    char **arr = my_calloc(3, 8);

    arr[0] = "setenv";
    arr[1] = "OLDPWD";
    arr[2] = my_calloc(255, 1);
    my_strcpy(arr[2], tofree->previous);
    set_env(arr, tofree, (int[2]){0, 1});
    free(arr[2]);
    free(arr);
}

void find_home(tofree_t *tofree)
{
    for (env_t *ex = tofree->first; ex; ex = ex->next) {
        if (my_strcmp(ex->name, "HOME") == 0) {
            if (chdir(ex->value) == -1) {
                my_dprintf(2, "cd: Can't change to home directory.\n");
                return;
            }
            getcwd(tofree->name, 255);
            modify_pwd(tofree);
            modify_oldpwd(tofree);
            return;
        }
    }
    my_dprintf(2, "cd: No home directory.\n");
}

void find_cd_error(char *name)
{
    struct dirent *dp = NULL;
    char *dir = get_direc(name);
    DIR *dirp = opendir(dir);
    char *newname = get_name(name);

    free(dir);
    for (; (dp = readdir(dirp));) {
        if (my_strcmp(dp->d_name, newname) == 0) {
            my_dprintf(2, "%s: Not a directory.\n", name);
            closedir(dirp);
            free(newname);
            return;
        }
    }
    my_printf("%s: No such file or directory.\n", name);
    closedir(dirp);
    free(newname);
}

void make_cd(char **arr, tofree_t *tofree, int *fd)
{
    (void)fd;
    if (arr[1] == NULL) {
        getcwd(tofree->previous, 255);
        find_home(tofree);
        return;
    } else if (arr[1][0] == '-' && arr[1][1] == 0) {
        free(arr[1]);
        arr[1] = my_calloc(255, 1);
        my_strcpy(arr[1], tofree->previous);
    }
    getcwd(tofree->previous, 255);
    if (chdir(arr[1]) == -1) {
        reset_buff(tofree->previous);
        find_cd_error(arr[1]);
        return;
    }
    getcwd(tofree->name, 255);
    modify_pwd(tofree);
    modify_oldpwd(tofree);
}
