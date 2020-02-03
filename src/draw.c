/*
** EPITECH PROJECT, 2019
** draw
** File description:
** draw anything in the window
*/
#include "game.h"
#include "entity.h"

void draw(core_t *core, entity_t *entity)
{
    switch (entity->type) {
    case SPRITE: case BUTTON:
        sfRenderWindow_drawSprite(core->window, entity->sprite->sprite, NULL);
        break;
    case TEXT:
        sfRenderWindow_drawText(core->window, entity->text->text, NULL);
        break;
    case TILE:
        sfRenderWindow_drawSprite(core->window,
                                entity->tile->entity->sprite->sprite, NULL);
        break;
    }
}

int vector_draw(void *entity, core_t *core, void *data)
{
    entity_t *ent = (entity_t *) entity;
    if (ent->active == 0) {
        if (core && entity)
            draw(core, ent);
        return (1);
    }
}