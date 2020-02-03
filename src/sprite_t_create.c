/*
** EPITECH PROJECT, 2019
** sprite_t_create
** File description:
** Create a sprite structure
*/

#include "entity.h"

sprite_t *sprite_t_create(const char *filepath)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    if (sprite == NULL)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    if (sprite->texture == NULL) {
        sfSprite_destroy(sprite);
        free(sprite);
        return NULL;
    }
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    return (sprite);
}