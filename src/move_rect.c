/*
** EPITECH PROJECT, 2019
** move_rect
** File description:
** move a rectangle
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Config.h>

int move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < rect->width * (max_value - 1)) {
        rect->left += offset;
        return (0);
    } else {
        rect->left = 0;
        return (1);
    }
}

int move_rect_grid(sfIntRect *rect, int offset, sfVector2i grid, int count)
{
    if (rect->left < rect->width * (grid.x - 1)) {
        rect->left += offset;
        return (0);
    } else {
        rect->left = 0;
        if (rect->top < rect->height * grid.y)
            rect->top += rect->height;
        else {
            rect->top = 0;
            return (1);
        }
    }
}