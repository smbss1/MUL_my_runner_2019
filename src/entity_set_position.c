/*
** EPITECH PROJECT, 2019
** entity_set_position
** File description:
** set the position of the entity
*/

#include "game.h"

void entity_set_position(entity_t *entity, sfVector2f pos)
{
    entity->position = pos;
    switch (entity->type) {
    case SPRITE: case BUTTON:
        sfSprite_setPosition(entity->sprite->sprite, entity->position);
        break;
    case TILE:
        sfSprite_setPosition(entity->tile->entity->sprite->sprite,
                                entity->position);
        break;
    case TEXT:
        sfText_setPosition(entity->text, entity->position);
        break;
    }
}