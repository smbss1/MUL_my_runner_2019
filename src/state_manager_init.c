/*
** EPITECH PROJECT, 2019
** state_manager_init
** File description:
** Init the state manager
*/

#include <stdlib.h>
#include "scene.h"
#include "game.h"

state_manager_t *state_manager_init(void)
{
    state_manager_t *state_manager = malloc(sizeof(state_manager_t));
    state_manager->stack = NULL;
    return (state_manager);
}