/*
** EPITECH PROJECT, 2019
** destroy_entity
** File description:
** destoy my entity
*/

#include "entity.h"
#include "game.h"

void destroy_entity(entity_t *entity)
{
    switch (entity->type)
    {
    case SPRITE: case BUTTON:
        sfSprite_destroy(entity->sprite->sprite);
        sfTexture_destroy(entity->sprite->texture);
        free(entity->sprite);
        break;
    case TEXT:
        sfFont_destroy(entity->text->font);
        sfText_destroy(entity->text->text);
        free(entity->text);
        break;
    case TILE:
        destroy_entity(entity->tile->entity);
        free(entity->tile);
        break;
    }
    free(entity);
}

void free_entity(void *entity)
{
    if (((entity_t *) entity)->is_animate == 1)
        sfClock_destroy(((entity_t *) entity)->clock_anim);
    if ((entity_t *) entity != NULL)
        destroy_entity((entity_t *) entity);
}