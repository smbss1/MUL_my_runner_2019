/*
** EPITECH PROJECT, 2019
** parallax_system
** File description:
** Manage a parallax effect
*/

#include "my.h"
#include "scene.h"
#include "entity.h"
#include <stdio.h>
#include <stdarg.h>

void parallax_system_move(sfSprite *sprite, sfVector2f speed, core_t *core)
{
    sfSprite_move(sprite, speed);
    sfVector2f sprite_pos = sfSprite_getPosition(sprite);
    sfIntRect sp_size = sfSprite_getTextureRect(sprite);
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(core->window));

    if (sprite_pos.x + sp_size.width < pos.x - SCREEN_WIDTH / 2) {
        sprite_pos = (sfVector2f){pos.x + SCREEN_WIDTH / 2, sprite_pos.y};
        sfSprite_setPosition(sprite, sprite_pos);
    }
}

void create_parallax(dictionary **dict, const char *filep, core_t *core, ...)
{
    va_list ap;
    va_start(ap, core);
    int cnt = va_arg(ap, int);
    sfVector2f speed = vector2f_set(va_arg(ap, double), 0);
    char name[100];

    for (int i = -1, j = 1, k = 0; i < (cnt * 2) - 1; i++, k++) {
        my_sprintf(&name, "%s%d.png", filep, j);
        entity_t *layer = create_entity(SPRITE, name);
        layer->speed = speed;
        my_sprintf(&name, "Layer %d", k);
        set_rb2d_collision(layer, -k, 10);
        if (i % 2 == 0) {
            j++;
            speed = vector2f_set(va_arg(ap, double), 0);
            entity_set_position(layer, vector2f_set(SCREEN_WIDTH, 0));
        }
        dictionary_add(dict, my_strdup(name), layer);
    }
    va_end(ap);
}