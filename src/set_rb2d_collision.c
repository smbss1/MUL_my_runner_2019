/*
** EPITECH PROJECT, 2019
** set_rb2d_collision
** File description:
** Set Rb2D od the entity
*/

#include "entity.h"

int set_rb2d_collision(entity_t *entity, int or_layer, int trigger)
{
    entity->order_layer = or_layer;
    entity->is_collide = 0;
    entity->is_trigger = trigger;
    entity->velocity.x = 200;
}