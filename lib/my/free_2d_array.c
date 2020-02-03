/*
** EPITECH PROJECT, 2019
** free_2D_array
** File description:
** Free a 2D array
*/

#include <stdlib.h>

void free_2d_array(void **array, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++)
        free(array[i]);
    free(array);
}