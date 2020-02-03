/*
** EPITECH PROJECT, 2019
** init_player
** File description:
** init the player entity
*/

#include "game.h"

void init_player(state_t *state)
{
    entity_t *player = create_entity(SPRITE, "sprite/player.png");
    set_rb2d_collision(player, 120, 0);
    player->active = 0;
    player->position.x = 50;
    player->position.y = 450;
    dictionary_add(&state->entities, "player", player);
}