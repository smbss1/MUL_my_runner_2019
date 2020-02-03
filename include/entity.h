/*
** EPITECH PROJECT, 2019
** entity
** File description:
** Header Entity Container
*/

#ifndef _ENTITY_
#define _ENTITY_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>

enum entity_type
{
    SPRITE,
    BUTTON,
    TEXT,
    SOUND,
    TILE
};

typedef struct s_sprite
{
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct s_text
{
    sfText *text;
    sfFont *font;
} text_t;

typedef struct s_music
{
    sfSoundBuffer *buffer;
    sfSound *sound;
    int is_playing;
} music_t;

typedef struct s_tile
{
    sfFloatRect rect;
    struct s_entity *entity;
    sfVector2u size;
    int is_damageable;
    int is_enemy;
    int win;
} tile_t;

typedef struct s_entity
{
    enum entity_type type;
    union
    {
        sprite_t *sprite;
        music_t *music;
        text_t *text;
        tile_t *tile;
    };
    int order_layer;
    sfVector2f speed;
    sfVector2f position;
    sfVector2f velocity;
    sfFloatRect rect;
    int is_jump;
    int is_collide;
    int is_trigger;
    int is_animate;
    sfClock *clock_anim;
    sfIntRect int_rect;
    int interval;
    int active;
} entity_t;

typedef struct s_layer
{
    sfVector2f speed;
    entity_t *entity;
    sfVector2f (*set_speed)(float x, float y);
    struct s_layer *next;
} layer_t;

typedef struct
{
    entity_t *layers;
} parallax_t;

typedef struct
{
    entity_t *tiles;
} tile_map_t;


void add_entity(entity_t **head_ref, entity_t *entity);
entity_t *create_entity(enum entity_type type, const char *fil);
void destroy_entity(entity_t *entity);
void free_entity(void *entity);
void entity_set_position(entity_t *entity, sfVector2f pos);

#endif