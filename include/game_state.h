/*
** EPITECH PROJECT, 2019
** game_state
** File description:
** Header game_state Container
*/

#ifndef _GAME_STATE_
#define _GAME_STATE_

#include "scene.h"

void init_game(state_t *state);
void update_game(state_t *state, float delta_time);
void draw_game(state_t *state);
void destroy_game(state_t *state);

#endif