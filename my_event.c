/*
** EPITECH PROJECT, 2019
** my_event
** File description:
** event handler
*/

#include "my_event.h"
#include "scene.h"

void on(core_t *core, char *name, void *handler)
{
    listener_t listener = {name, handler};
    core->listeners[core->list_count] = listener;
    core->list_count++;
}

void emit(core_t *core, char *name, void *value)
{
    for (int i = 0; i < core->list_count; i++) {
        if (my_strcmp(name, core->listeners[i].name) == 0)
            core->listeners[i].handle(value);
    }
}