/*
** EPITECH PROJECT, 2019
** menu_state
** File description:
** Menu State Function
*/

#include "entity.h"
#include "scene.h"
#include "my.h"
#include "game.h"

void init_menu(state_t *state)
{
    entity_t *play = create_entity(BUTTON, "sprite/play_btn.png");
    entity_t *quit = create_entity(BUTTON, "sprite/quit_btn.png");

    entity_set_position(play, vector2f_set(SCREEN_WIDTH/2 - 60,
                                                SCREEN_HEIGHT/2));
    entity_set_position(quit, vector2f_set(SCREEN_WIDTH/2 - 60,
                                            SCREEN_HEIGHT/2 + 110));
    dictionary_add(&state->buttons, "Play", play);
    dictionary_add(&state->buttons, "Quit", quit);
    my_printf("init menu\n");
}

void draw_menu(state_t *state)
{
    dictionary_foreach_value_c(state->entities, vector_draw, state->core, NULL);
    dictionary_foreach_value_c(state->buttons, vector_draw, state->core, NULL);
    sfRenderWindow_setView(state->core->window,
                            sfRenderWindow_getDefaultView(state->core->window));
}

void destroy_menu(state_t *state)
{
    dictionary_foreach_value(state->buttons, free_entity);
    dictionary_foreach_value(state->entities, free_entity);
    dictionary_delete_all(state->entities);
    dictionary_delete_all(state->entities);
    my_printf("menu destroy\n");
}
