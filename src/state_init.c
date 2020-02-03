/*
** EPITECH PROJECT, 2019
** state_init
** File description:
** init a state
*/

#include <stdlib.h>
#include "scene.h"
#include "game.h"

state_t *state_init(void (*init)(state_t *state),
                    void (*poll)(core_t *core),
                    void (*update)(state_t *state, float time),
                    void (*draw)(state_t *state),
                    void (*destroy)(state_t *state),
                    core_t *core)
{
    state_t *state = malloc(sizeof(state_t));
    state->draw = draw;
    state->destroy = destroy;
    state->poll_event = poll;
    state->update = update;
    state->entities = NULL;
    state->buttons = NULL;
    state->next = NULL;
    state->core = core;
    if (init != NULL)
        init(state);
    return (state);
}