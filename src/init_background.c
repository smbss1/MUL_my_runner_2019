/*
** EPITECH PROJECT, 2019
** init_background
** File description:
** init the background sprite
*/

#include "game.h"

void init_background(state_t *state)
{
    entity_t *bg = create_entity(SPRITE, "sprite/BG.png");
    entity_t *bg1 = create_entity(SPRITE, "sprite/BG.png");
    bg->order_layer = -15;
    bg->is_trigger = 10;
    bg1->order_layer = -18;
    bg1->is_trigger = 10;
    entity_set_position(bg1, vector2f_set(SCREEN_WIDTH, 0));
    dictionary_add(&state->entities, "background", bg);
    dictionary_add(&state->entities, "background1", bg1);
}