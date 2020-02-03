/*
** EPITECH PROJECT, 2019
** get_variable
** File description:
** Get Variable in a Text
*/

#include <stdlib.h>
#include "my.h"

char *get_variable_name(char *str, char *word)
{
    char delim[] = " :\n";
    char *var;
    char *dup = my_strdup(str);

    my_strtok(dup, delim, &var);

    while (var != NULL) {
        if (my_strcmp(var, word) == 0) {
            return (var);
            break;
        }
        my_strtok(NULL, delim, &var);
    }
    free (dup);
}

char *get_str(char *str, char *word)
{
    char delim[] = ", :\n";
    char *var;
    char *dup = my_strdup(str);

    my_strtok(dup, delim, &var);

    while (var != NULL) {
        if (my_strcmp(var, word) == 0) {
            my_strtok(NULL, delim, &var);
            return (var);
        }
        my_strtok(NULL, delim, &var);
    }
    free (dup);
}

int get_number(char *str, char *word)
{
    char delim[] = ", :\n";
    char *var;
    char *dup = my_strdup(str);

    my_strtok(dup, delim, &var);

    while (var != NULL) {
        if (my_strcmp(var, word) == 0) {
            my_strtok(NULL, delim, &var);
            my_printf("We find the value of %s is %s\n", word, var);
            return (my_getnbr(var));
        }
        my_strtok(NULL, delim, &var);
    }
    free (dup);
}