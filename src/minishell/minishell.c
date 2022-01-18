/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** minishell
*/

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "minishell.h"

int my_execve(char *path, char **argv, char **env)
{
    int pid = 0;
    int *stat_loc = my_memset(sizeof(int *), NULL);

    if ((pid = fork()) == 0) {
        execve(path, argv, env);
        exit(84);
    }
    waitpid(pid, stat_loc, 0);
    if (WIFEXITED(*stat_loc))
        if (WEXITSTATUS(*stat_loc) == 84)
            return my_put_error("Command does not exists\n");
    else if (WIFSIGNALED(*stat_loc))
        my_printf("%s\n", strsignal(WTERMSIG(*stat_loc)));
    return 0;
}

char *format_params(char **params, char **env)
{
    char **path = NULL;
    char *tmp = NULL;
    int index = 0;
    char *filename = NULL;

    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            tmp = &(env[i][5]);
    if (**params == '.', (*params)[1] == '/')
        return &(*params)[2];
    path = my_str_to_word_array(tmp, ':');
    if (path == NULL)
        path = my_memset(sizeof(char) * 8, "/usr/bin");
    while (path[index] != NULL && is_exec(filecat(path[index], *params)) == 84)
        index++;
    if (path[index] == NULL)
        return NULL;
    filename = filecat(path[index], *params);
    return filecat(path[index], *params);
}

int execute(char *str, char **env)
{
    char **params = NULL;
    char *path = NULL;

    if (str[0] == '\n')
        return 0;
    params = get_params(str);
    path = format_params(params, env);
    if (is_exec(path) == 0) {
        my_put_error(path);
        return my_put_error(": Permission denied\n");
    }
    my_execve(path, params, env);
    free_params(params);
}

int minishell(char **env)
{
    char *str = NULL;
    size_t len = 0;
    long int end = 0;

    while (end >= 0) {
        write(2, "$> ", 3);
        end = getline(&str, &len, stdin);
        if (my_strcmp("exit", str) == 0)
            break;
        if (end == -1)
            my_putstr("exit\n");
        else
            execute(str, env);
    }
    free(str);
    return 0;
}
