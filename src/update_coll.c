/*
** EPITECH PROJECT, 2019
** update_coll
** File description:
** update collision btw 2 entity
*/

#include "entity.h"
#include "scene.h"

int is_grounded(entity_t *player, entity_t *ent)
{
    if (player->is_jump == 0) {
        player->position.y = ent->rect.top - player->rect.height;
        player->velocity.y = 0.1f;
    } else
        player->is_jump = 0;
}

int update_coll(void *entity, void *ent_pl, core_t *core)
{
    entity_t *player = (entity_t *) ent_pl;
    entity_t *ent = (entity_t *) entity;
    update_rect(player);
    update_rect(ent);
    int collision = sfFloatRect_intersects(&player->rect, &ent->rect, NULL);

    if (ent->is_trigger == 1 &&
        ent->is_animate == 1 &&
        collision &&
        ent->active == 0) {
        core->score++;
        ent->active = -1;
    }
    if (player->rect.top + player->rect.height > SCREEN_HEIGHT)
        core->exit = 0;
    if (ent->is_trigger == 0 && collision) {
        if (player->rect.top < ent->rect.top)
            is_grounded(player, ent);
        else if (player->rect.left < ent->rect.left)
            return (game_over(core));
    } else if (ent->is_trigger == 1 && collision)
        if (ent->tile->is_enemy)
            return (game_over(core));
    if (ent->tile->win == 1 && collision)
        emit(core, "player_win", core);
    return (1);
}