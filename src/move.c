/*
** EPITECH PROJECT, 2019
** update_movement
** File description:
** update the player velocity
*/

#include "game.h"
#include "scene.h"

int move(void *entity, core_t *core, void *data)
{
    entity_t *ent = (entity_t *) entity;
    if (ent->type == SPRITE)
        parallax_system_move(ent->sprite->sprite, ent->speed, core);
    if (ent->type == TILE && ent->is_animate == 1) {
        play_animation_grid(&ent->int_rect,
                            ent->clock_anim, 0.1f, (sfVector2i){1, 4});
    sfSprite_setTextureRect(ent->tile->entity->sprite->sprite, ent->int_rect);
    }
    return (1);
}