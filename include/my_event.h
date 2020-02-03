/*
** EPITECH PROJECT, 2019
** my_event
** File description:
** Header Event Container
*/

#ifndef _MY_EVENT_
#define _MY_EVENT_

typedef struct listener_t
{
    char *name;
    void (*handle)(void *);
} listener_t;

#endif