/*
** EPITECH PROJECT, 2019
** update
** File description:
** Game Loop
*/

#include <stdlib.h>
#include "game.h"
#include "entity.h"
#include "scene.h"
#include "ui.h"
#include "game_state.h"

void state_manager_push(state_manager_t **, state_t *);

void level_events(core_t *core);

void player_win(void *data);

int mouse_over_button(entity_t *btn, sfVector2i mouse_pos)
{
    if (sfFloatRect_contains(&btn->rect, mouse_pos.x, mouse_pos.y))
        return (1);
    return (0);
}

int mouse_over_entity_button(entity_t *btn, sfVector2i mouse_pos)
{
    if (btn != NULL && btn->type == BUTTON) {
        btn->rect = sfSprite_getGlobalBounds(btn->sprite->sprite);
        if (sfFloatRect_contains(&btn->rect, mouse_pos.x, mouse_pos.y))
            return (1);
    }
    return (0);
}

void start(core_t *core)
{
    init_window(core);
    core->state_manager = state_manager_init();
    if (!core->state_manager)
        return;
    core->menu_state = state_init(init_menu, menu_events,
                                    NULL, draw_menu,
                                    destroy_menu, core);
    core->game_state = state_init(init_game, game_events,
                                    update_game, draw_game,
                                    destroy_game, core);
    state_manager_push(&core->state_manager, core->game_state);
    state_manager_push(&core->state_manager, core->menu_state);
    on(core, "player_win", player_win);
    on(core, "player_jump", sfSound_play);
    update(core);
}

void update(core_t *core)
{
    float dt = 0;
    core->state_manager->clock = sfClock_create();
    while (sfRenderWindow_isOpen(core->window)) {
        core->state_manager->time = sfClock_restart(core->state_manager->clock);
        dt = sfTime_asSeconds(core->state_manager->time);
        sfRenderWindow_clear(core->window, sfBlack);
        state_manager_event(core->state_manager);
        state_manager_update(core->state_manager, &dt, core);
        state_manager_draw(core->state_manager);
        sfRenderWindow_display(core->window);
        if (core->exit > -1)
            sfWindow_close(core->window);
    }
    if (!state_manager_contain(core->state_manager, core->menu_state))
        state_manager_push(&core->state_manager, core->menu_state);
    sfClock_destroy(core->state_manager->clock);
    state_manager_free(core->state_manager);
    sfRenderWindow_destroy(core->window);
}