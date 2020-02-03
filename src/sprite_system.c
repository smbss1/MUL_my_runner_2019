/*
** EPITECH PROJECT, 2019
** background_system
** File description:
** Manage the background
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include "game.h"

void init_sprite_system(sfSprite **sprite, sfTexture *texture, char *filePath)
{
    if (sprite != NULL)
        *sprite = sfSprite_create();
    texture = sfTexture_createFromFile(filePath, NULL);

    if (texture != NULL && sprite != NULL)
        sprite_system_set_texture(*sprite, texture);
}

void sprite_system_set_texture(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
}

void sprite_system_draw(sfSprite *sprite, core_t *core)
{
    sfRenderWindow_drawSprite(core->window, sprite, NULL);
}

void sprite_system_destroy(sfSprite *sprite, sfTexture *texture)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void sprite_system_setTextureRect(sfSprite *sprite, sfIntRect rec)
{
    sfSprite_setTextureRect(sprite, rec);
}