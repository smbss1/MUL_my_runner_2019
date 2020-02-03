/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** Func that displaythe content of an array of words
*/

#include "../../include/my.h"

static int my_array_length(char * const *tab)
{
    int len;

    for (int i = 0; tab[i] != 0; i++) {
        len++;
    }
    return (len);
}

int my_show_word_array(char * const *tab)
{
    char *str0 = my_strdup("");
    int i = 0;

    for (; tab[i] != 0; i++) {
        char *str = my_strdup(tab[i]);
        my_strcat(str, "\n");
        my_strcat(str0, str);
    }
    my_putstr(str0);
    return (0);
}