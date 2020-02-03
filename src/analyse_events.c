/*
** EPITECH PROJECT, 2019
** analyse_events
** File description:
** Analyse Events like close Window
*/

#include "game.h"
#include "ui.h"
#include "scene.h"

void level_events(core_t *core);

void mouse_pressed(entity_t *p, sfVector2i po, core_t *core)
{
    if (mouse_over_entity_button(p, po))
        state_manager_pop(&core->state_manager, 0);
}

void menu_events(core_t *core)
{
    state_t *state = state_manager_top(core->state_manager);
    entity_t *play = dictionary_getvalue(&state->buttons, "Play");
    entity_t *quit = dictionary_getvalue(&state->buttons, "Quit");

    while (sfRenderWindow_pollEvent(core->window, &core->event)) {
        sfVector2i mouse_pos = sfMouse_getPosition(core->window);
        if (core->event.type == sfEvtClosed)
            close_window(core->window);
        if (core->event.type == sfEvtMouseButtonPressed) {
            mouse_pressed(play, mouse_pos, core);
            if (mouse_over_entity_button(quit, mouse_pos))
                close_window(core->window);
        }
        if (core->event.type == sfEvtMouseMoved)
            menu_mouse_move(mouse_pos, play, quit);
    }
}

void game_events(core_t *core)
{
    state_t *state = state_manager_top(core->state_manager);
    entity_t *player =
            (entity_t *)dictionary_getvalue(&state->entities, "player");

    while (sfRenderWindow_pollEvent(core->window, &core->event)) {
        if (core->event.type == sfEvtClosed)
            close_window(core->window);
        if (core->event.type == sfEvtKeyPressed &&
            core->event.key.code == sfKeyP)
            state_manager_push(&core->state_manager, core->menu_state);
        if (core->event.type == sfEvtKeyPressed &&
                core->event.key.code == sfKeyUp &&
                player->is_jump == 0) {
                player->velocity.x = 200;
                player->velocity.y = -500;
                player->is_jump = 1;
                emit(core, "player_jump", core->jump_sound.sound);
        }
    }
}