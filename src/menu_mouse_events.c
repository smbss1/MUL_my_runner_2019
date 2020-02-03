/*
** EPITECH PROJECT, 2019
** menu_events
** File description:
** Events for the menu
*/

#include "game.h"
#include "ui.h"
#include "scene.h"

void menu_mouse_move(sfVector2i mouse_pos, entity_t *play, entity_t *quit)
{
    sfColor normal = {255, 255, 255, 255};
    sfColor highlight = {250, 20, 20, 255};

    if (mouse_over_entity_button(play, mouse_pos))
        sfSprite_setColor(play->sprite->sprite, highlight);
    else
        sfSprite_setColor(play->sprite->sprite, normal);
    if (mouse_over_entity_button(quit, mouse_pos))
        sfSprite_setColor(quit->sprite->sprite, highlight);
    else
        sfSprite_setColor(quit->sprite->sprite, normal);
}