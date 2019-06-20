/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** simon-perraud
*/

#ifndef __MYP__
#define __MYP__

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#define IS_NOT_NUM (str[i] < '0' || str[i] > '9')
#define IS_NOT_MAJ_ALPHA (str[i] < 'A' || str[i] > 'Z')
#define IS_NOT_ALPHA (str[i] < 'a' || str[i] > 'z')
#define IS_NOT_ALPHANUM IS_NOT_NOT_NUM && IS_NOT_MAJ_ALPHA && IS_NOT_ALPHA
#define SEPARATOR "\n\t!\"#$%&'()*+,-./:;<=>?@[]\\^_`{|}~ "
#define IS_RETURN (str[i] == 10)

#endif /* __MY__ */
