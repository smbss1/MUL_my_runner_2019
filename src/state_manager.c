/*
** EPITECH PROJECT, 2019
** state_manager_init
** File description:
** init a state manager
*/

#include <stdlib.h>
#include "scene.h"

void state_manager_pop(state_manager_t **state_manager, int delete)
{
    state_t *state = (*state_manager)->stack;
    (*state_manager)->stack = (*state_manager)->stack->next;
    if (state->destroy != NULL && delete) {
        state->destroy(state);
        free(state);
    }
}

state_t *state_manager_top(state_manager_t *state_manager)
{
    return (state_manager->stack);
}

void state_manager_push(state_manager_t **state_manager, state_t *state)
{
    if (state != NULL) {
        state->next = (*state_manager)->stack;
        (*state_manager)->stack = state;
    }
}

void state_manager_event(state_manager_t *st_m)
{
    state_t *state = state_manager_top(st_m);
    if (state->poll_event != NULL)
        state->poll_event(state->core);
}

void state_manager_free(state_manager_t *state_manager)
{
    state_t *temp = NULL;

    while (state_manager->stack != NULL) {
        temp = state_manager->stack;
        if (temp && temp->destroy != NULL)
            temp->destroy(temp);
        state_manager->stack = state_manager->stack->next;
        free(temp);
        temp = NULL;
    }
    state_manager->stack = NULL;
    free (state_manager);
}