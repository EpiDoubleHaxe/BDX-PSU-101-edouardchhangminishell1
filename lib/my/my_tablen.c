/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** my_tablen
*/

#include <stddef.h>

int my_tablen(void **tab)
{
    int len = 0;

    if (tab == NULL)
        return -1;
    for (len = 0; tab[len] != NULL; len++);
    return len;
}
