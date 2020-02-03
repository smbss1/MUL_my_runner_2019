/*
** EPITECH PROJECT, 2019
** create_int_rect
** File description:
** Create a new sfIntRect and return this address
*/

#include "game.h"

sfIntRect create_int_rect(int left, int top, int width, int height)
{
    sfIntRect rect = { left, top, width, height };
    return rect;
}

sfFloatRect create_float_rect(float left, float top, float width, float height)
{
    sfFloatRect rect = { left, top, width, height };
    return rect;
}