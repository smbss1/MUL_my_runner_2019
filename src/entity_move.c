/*
** EPITECH PROJECT, 2019
** entity_move
** File description:
** Move an entity
*/

#include "entity.h"

void entity_move(entity_t *entity, sfVector2f speed)
{
    switch (entity->type) {
    case SPRITE:
        sfSprite_move(entity->sprite->sprite, speed);
        break;
    case TEXT:
        sfText_move(entity->text, speed);
        break;
    }
}