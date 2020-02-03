/*
** EPITECH PROJECT, 2019
** scene
** File description:
** Header scene Container
*/

#ifndef _SCENE_
#define _SCENE_

#include "game.h"
#include "entity.h"
#include "my_event.h"
#include "my.h"

typedef struct core core_t;
typedef struct s_state state_t;
typedef struct stat_manager state_manager_t;

typedef struct s_state
{
    dictionary *entities;
    dictionary *buttons;
    parallax_t *parallax;
    core_t *core;

    void (*poll_event)(core_t *core);
    void (*update)(struct s_state *state, float dt, core_t *core);
    void (*draw)(struct s_state *state);
    void (*destroy)(struct s_state *state);
    struct s_state *next;
};

struct stat_manager {
    state_t *stack;
    sfClock *clock;
    sfTime time;
};

struct core {
    state_manager_t *state_manager;
    state_t *game_state;
    state_t *menu_state;
    sfRenderWindow *window;
    sfEvent event;
    sfView *view;
    int exit;
    char *filename;
    music_t main_music;
    music_t jump_sound;
    sfFont *font;
    sfText *scoretxt;
    char score_char[200];
    int score;
    listener_t listeners[100];
    int list_count;
};

void init_menu(state_t *state);
void draw_menu(state_t *state);
void destroy_menu(state_t *state);
void init_level(state_t *state);
void draw_level(state_t *state);
void destroy_level(state_t *state);
void menu_events(core_t *core);
void game_events(core_t *core);

void parallax_system_move(sfSprite *sprite, sfVector2f speed, core_t *core);
int vector_draw(void *entity, core_t *core, void *data);
void draw(core_t *core, entity_t *entity);
int update_coll(void *entity, void *ent_pl, core_t *core);


#endif