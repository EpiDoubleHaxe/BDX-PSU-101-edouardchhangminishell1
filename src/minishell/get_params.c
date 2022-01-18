/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** get_params
*/

#include <stdlib.h>

#include "my.h"
#include "minishell.h"

char **clean_str(char **str)
{
    int index = 0;
    int len = 0;

    for (index = 0; str[index] != NULL; index++);
    len = my_strlen(str[index - 1]);
    str[index - 1][len - 1] = '\0';
    return str;
}

char **get_params(char *str)
{
    char **params = my_str_to_word_array(str, ' ');

    params = clean_str(params);
    return params;
}

void free_params(char **params)
{
    for (int i = 0; params[i] != NULL; i++)
        free(params[i]);
    free(params);
}
