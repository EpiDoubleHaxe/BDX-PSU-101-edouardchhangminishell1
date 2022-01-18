/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stddef.h>
#include <unistd.h>

#include "my.h"
#include "minishell.h"

int minishell(char **env);

int main(int argc, char **argv, char **env)
{
    if (argc <= 1)
        return minishell(env);
    return my_put_error("Invalid args\n");
}
