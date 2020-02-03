/*
** EPITECH PROJECT, 2019
** state_manager_draw
** File description:
** manager draw
*/

#include <stdlib.h>
#include "scene.h"

void state_manager_draw(state_manager_t *state_manager)
{
    state_t *state = state_manager_top(state_manager);
    if (state->draw != NULL)
        state->draw(state);
}