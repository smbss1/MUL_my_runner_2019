/*
** EPITECH PROJECT, 2019
** sfVector2f_set
** File description:
** set the value of a vector2f
*/

#include "game.h"

sfVector2f vector2f_set(float x, float y)
{
    sfVector2f vector = {x, y};
    return (vector);
}

sfVector2i vector2i_set(float x, float y)
{
    sfVector2i vector = {x, y};
    return (vector);
}