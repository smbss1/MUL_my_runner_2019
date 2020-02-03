/*
** EPITECH PROJECT, 2019
** dictionary_foreach
** File description:
** loop a list
*/

#include <stdlib.h>
#include "my.h"

typedef int (*call3)(void *, void *, void *);

void dictionary_foreach(dictionary *v, int (*callback)(char *, void *))
{
    dictionary *node = v;
    int result = 1;
    while (node != NULL && result) {
        if (callback != NULL)
            result = callback(node->key, node->data);
        node = node->next;
    }
}

void dictionary_foreach_value(dictionary *v, int (*callback)(void *))
{
    dictionary *node = v;
    int result = 1;
    while (node != NULL && result) {
        if (callback != NULL)
            result = callback(node->data);
        node = node->next;
    }
}

void dictionary_foreach_key(dictionary *v, int (*callback)(char *))
{
    dictionary *node = v;
    int result = 1;
    while (node != NULL && result) {
        if (callback != NULL)
            result = callback(node->key);
        node = node->next;
    }
}

int dictionary_foreach_value_c(dictionary *v, call3 c, void *d1, void *d2)
{
    dictionary *node = v;
    int result = 1;
    while (node != NULL && result) {
        if (c != NULL)
            result = c(node->data, d1, d2);
        node = node->next;
    }
    return (result);
}

int dictionary_compare_key(dictionary *v, char *key)
{
    dictionary *node = v;
    int result = 0;
    while (node != NULL) {
        if (my_strcmp(node->key, key) == 0)
            result = 1;
        node = node->next;
    }
    return (result);
}