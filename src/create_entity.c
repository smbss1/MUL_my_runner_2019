/*
** EPITECH PROJECT, 2019
** create_entity
** File description:
** Create an entity
*/

#include <stdlib.h>
#include "game.h"
#include "entity.h"

void malloc_tile(entity_t **entity, char *file)
{
    (*entity)->tile = malloc(sizeof(tile_t));
    if ((*entity)->tile == NULL) {
        destroy_entity(entity);
        return NULL;
    }
    (*entity)->tile->entity = create_entity(SPRITE, file);
    (*entity)->tile->size = sfTexture_getSize((*entity)->tile->entity->sprite->
                                                        texture);
    entity_set_position(*entity, (*entity)->position);
}

void malloc_sprite(entity_t **entity, char *file)
{
    (*entity)->sprite = sprite_t_create(file);
    if ((*entity)->sprite == NULL) {
        destroy_entity(*entity);
    }
}

entity_t *create_entity(enum entity_type type, const char *fil)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->type = type;

    if (entity == NULL)
        return NULL;
    switch (entity->type) {
    case SPRITE: case BUTTON:
        malloc_sprite(&entity, fil);
        break;
    case SOUND:
        entity->music->sound = sfSound_create();
        entity->music->buffer = sfSoundBuffer_createFromFile(fil);
        break;
    case TILE:
        malloc_tile(&entity, fil);
        break;
    }
    return (entity);
}