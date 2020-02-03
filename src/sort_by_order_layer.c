/*
** EPITECH PROJECT, 2019
** sort_by_order_layer
** File description:
** sort entity by order layer
*/

#include "game.h"
#include "entity.h"
#include "scene.h"
#include "ui.h"

int sort_by_order_layer(void *a, void *b)
{
    dictionary *dict1 = (dictionary *)a;
    dictionary *dict2 = (dictionary *)b;
    entity_t *ent1 = (entity_t *) dict1->data;
    entity_t *ent2 = (entity_t *) dict2->data;
    int nb1 = ent1->order_layer;
    int nb2 = ent2->order_layer;

    if (nb1 < nb2)
        return (-1);
    else if (nb1 > nb2)
        return (1);
    else
        return (0);
}