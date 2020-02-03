/*
** EPITECH PROJECT, 2019
** state_manager_contain
** File description:
** contain
*/

#include "scene.h"

int state_manager_contain(state_manager_t *state_manager, state_t *state)
{
    for (state_t *s = state_manager->stack; s; s = s->next) {
        if (s == state)
            return (1);
    }
    return (0);
}