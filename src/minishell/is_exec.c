/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** fis_exec
*/

#include "my.h"

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int is_exec(char *fp)
{
    struct stat *file = my_memset(sizeof(struct stat), NULL);

    if (stat(fp, file) == -1)
        return 84;
    if (file->st_mode & S_IXUSR && file->st_mode & S_IFREG)
        return 1;
    return 0;
}
