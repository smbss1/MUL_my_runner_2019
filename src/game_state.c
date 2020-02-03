/*
** EPITECH PROJECT, 2019
** game_state
** File description:
** all game func for the game state
*/

#include "game.h"
#include "entity.h"
#include "scene.h"
#include "ui.h"

int move(void *entity, core_t *core, void *data);

int text(char *key);

void create_parallax(dictionary **dict, const char *filep, int cnt, ...);

int update_coll(void *entity, void *ent_pl, core_t *core);

void init_game(state_t *state)
{
    dictionary *tile_files = NULL;
    init_tiles_sprite(&tile_files);
    init_camera(state->core);
    create_parallax(&state->entities,
                    "sprite/Layer", state->core, 3, -1.2f, -0.7f, -0.4f);
    init_player(state);
    init_background(state);
    char **map = load_2d_arr_from_file(state->core->filename, MAP_ROW, MAP_COL);
    if (map != NULL) {
        tile_map(state, &tile_files, map);
        free_2d_array(map, MAP_ROW);
    } else {
        my_printf("Error map not valid\n");
        state->core->exit = 84;
    }
    dictionary_sort(&state->entities, sort_by_order_layer);
    init_music(state->core);
    init_score_text(state->core);
    my_printf("init game\n");
}

void update_movement(float dt, entity_t *player)
{
    player->velocity.y += gravity * dt * 120;
    player->position.x += player->velocity.x * dt;
    player->position.y += player->velocity.y * dt;
}

void update_game(state_t *state, float dt, core_t *core)
{
    if (state->core->main_music.is_playing == 0) {
        sfSound_play(state->core->main_music.sound);
        state->core->main_music.is_playing = 1;
    }
    entity_t *player;
    player = (entity_t *)dictionary_getvalue(&state->entities, "player");
    dictionary_foreach_value_c(state->entities, move, core, NULL);
    update_movement(dt, player);
    dictionary_foreach_value_c(state->entities,
                                update_coll, player, state->core);
    sfSprite_setPosition(player->sprite->sprite, player->position);
    update_camera(player, dt, core);
    sfRenderWindow_setView(core->window, core->view);
    sfVector2f view_center = sfView_getCenter(core->view);
    sfText_setPosition(state->core->scoretxt,
        (sfVector2f) {view_center.x - 900, view_center.y - 450});
    my_sprintf(&state->core->score_char, "Score: %d", state->core->score);
}

void draw_game(state_t *state)
{
    sfText_setString(state->core->scoretxt, state->core->score_char);
    dictionary_foreach_value_c(state->entities, vector_draw, state->core, NULL);
    sfRenderWindow_drawText(state->core->window, state->core->scoretxt, NULL);
}

void destroy_game(state_t *state)
{
    dictionary_foreach_value(state->entities, free_entity);
    dictionary_foreach_value(state->buttons, free_entity);
    dictionary_delete_all(state->entities);
    dictionary_delete_all(state->buttons);
    sfSoundBuffer_destroy(state->core->main_music.buffer);
    sfSound_destroy(state->core->main_music.sound);
    sfSoundBuffer_destroy(state->core->jump_sound.buffer);
    sfSound_destroy(state->core->jump_sound.sound);
    sfFont_destroy(state->core->font);
    my_printf("game destroy\n");
}