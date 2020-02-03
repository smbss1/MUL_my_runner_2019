/*
** EPITECH PROJECT, 2019
** update_rect
** File description:
** Update the rectangle collision of the entity
*/

#include "entity.h"

void update_rect(entity_t *ent)
{
    if (ent->type == SPRITE)
        ent->rect = sfSprite_getGlobalBounds(ent->sprite->sprite);
    else if (ent->type == TILE)
        ent->rect = sfSprite_getGlobalBounds(ent->tile->entity->sprite->sprite);
    return (1);
}