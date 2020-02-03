/*
** EPITECH PROJECT, 2019
** state_manager_update
** File description:
** Update func
*/

#include <stdlib.h>
#include "scene.h"
#include "game.h"

void state_manager_update(state_manager_t *state_manager, const float *dt,
                                                            core_t *core)
{
    state_t *state = state_manager_top(state_manager);
    if (state->update != NULL)
        state->update(state, *dt, core);
}