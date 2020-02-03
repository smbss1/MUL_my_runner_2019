/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Func that splits a string into words
*/

#include <stdlib.h>
#include "my.h"

static int my_array_length1(char const *str)
{
    int len = my_strlen(str) - 1;
    int array_len = 0;
    int separator = 0;

    for (int i = 0; i < len; i++) {
        if (!my_char_isalpha(str[i]) && !my_char_isnum(str[i])) {
            separator = 1;
        } else {
            if (separator == 1) {
                separator = 0;
                array_len++;
            }
        }
    }
    array_len++;
    return (array_len);
}

static int have_separator(int *separator, int *k)
{
    if (*separator == 1) {
        *separator = 0;
        *k += 1;
    }
}

char **my_str_to_word_array(char const *str)
{
    int len = my_strlen(str);
    int array_len = my_array_length1(str);
    char **array = malloc(sizeof(char *) * (array_len + 1));
    int separator;

    for (int i = 0; i < array_len; i++)
        array[i] = malloc(sizeof(char) * 1);
    for (int i = 0, j = 0, k = 0; i < len; i++) {
        if (!my_char_isalpha(str[i]) && !my_char_isnum(str[i])) {
            j = 0;
            separator = 1;
        } else {
            have_separator(&separator, &k);
            array[k][j] = str[i];
            j++;
        }
    }
    return (array);
}