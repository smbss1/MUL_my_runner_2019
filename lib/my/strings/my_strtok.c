/*
** EPITECH PROJECT, 2019
** my_strtok
** File description:
** Parse
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char *my_strtok(char *str, char *delim, char **endptr)
{
    static char *next;
    char *current = 0;

    if (str) {
        current = str;
        while (my_strchr(delim, *str) == NULL)
            str++;
        next = *str == 0 ? str : str + 1;
        *str = 0;
    } else if (*next != 0) {
        current = next;
        while (my_strchr(delim, *next) == NULL)
            next++;
        if (*next != 0) {
            *next = 0;
            next++;
        }
    }
    if (endptr != NULL)
        *endptr = current;
    return (current);
}