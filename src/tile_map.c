/*
** EPITECH PROJECT, 2019
** tile_map
** File description:
** Create a Tilemap
*/

#include "game.h"

void init_coin(state_t *state, entity_t *t, char *j_char, char *key)
{
    if (my_strcmp(key, "o") == 0) {
        t->is_animate = 1;
        t->clock_anim = sfClock_create();
        t->interval = 1;
        t->is_trigger = 1;
        t->int_rect = (sfIntRect) {0, 0, 40, 44};
        dictionary_add(&state->entities, my_strdup(j_char), t);
    }
}

void init_tile(entity_t *t, int layer, char key)
{
    t->order_layer = layer;
    t->active = 0;
    t->is_trigger = (key == '2') ? 1:0;
    t->is_trigger = (key == '7') ? 1:t->is_trigger;
    t->tile->is_enemy = (key == '2') ? 1:0;
    t->tile->win = (key == '7') ? 1:0;
}

void tile_map(state_t *state, dictionary **di, char **map)
{
    char j_char[80];
    char key[80];

    for (int i = 0, l = 8; i < MAP_ROW; i++)
        for (int j = 0; j < MAP_COL; j++) {
            my_sprintf(&key, "%c", map[i][j]);
            if (dictionary_key_exists(di, key)) {
                sfVector2f pos = vector2f_set(j * 50, i * 50);
                entity_t *t = create_entity(TILE, dictionary_getvalue(di, key));
                sfSprite_setPosition(t->tile->entity->sprite->sprite, pos);
                my_sprintf(&j_char, "Tile %d", l);
                init_tile(t, l++, map[i][j]);
                init_coin(state, t, j_char, key);
                dictionary_add(&state->entities, my_strdup(j_char), t);
            }
        }
}