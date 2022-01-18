/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stddef.h>

void *my_memset(int size, char *str);
int my_strlen(char const *c);

static char **alloc_matrix(char const *str, char sep)
{
    int h = 0;
    int is_word = 0;
    int len = 0;
    char **array = NULL;

    while (str[h] != '\0') {
        if (str[h] != sep) {
            is_word = 1;
        } else if (is_word == 1) {
            len++;
            is_word = 0;
        }
        h++;
    }
    if (is_word == 1)
        len++;
    array = my_memset(sizeof(char *) * (len + 1), NULL);
    return (array);
}

static int alloc_char(char const *str, char **array, char sep)
{
    int j = 0;
    int len_word = 0;
    int count = 0;
    int is_word = 0;

    while (str[j] != '\0') {
        if (str[j] != sep) {
            len_word++;
        } else if (len_word != 0) {
            array[count] = my_memset(sizeof(char) * (len_word + 1), NULL);
            len_word = 0;
            count++;
        }
        j++;
    }
    if (len_word != 0) {
        array[count] = my_memset(sizeof(char) * (len_word + 1), NULL);
        len_word = 0;
    }
    return (0);
}

char **word_array(char const *str, char sep)
{
    int count = 0;
    char **array = 0;
    int k = 0;
    int is_word = 0;

    for (int l = 0; str[l] != '\0'; l++) {
        if (str[l] != sep) {
            array[k][count] = str[l];
            count++;
            is_word = 1;
        } else if (is_word == 1) {
            array[k][count] = '\0';
            count = 0;
            k++;
            is_word = 0;
        }
    }
    return (array);
}

char **my_str_to_word_array(char const *str, char sep)
{
    array = alloc_matrix(str, sep);
    alloc_char(str, array, sep);
}