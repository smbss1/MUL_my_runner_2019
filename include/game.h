/*
** EPITECH PROJECT, 2019
** game
** File description:
** Header game Container
*/

#ifndef _RUNNER_
#define _RUNNER_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Config.h>

#include "entity.h"
#include "scene.h"

static const SCREEN_WIDTH = 1920;
static const SCREEN_HEIGHT = 1080;
static const MAP_ROW = 20;
static const MAP_COL = 120;
static const float gravity = 9.81f;

sfVector2f vector2f_set(float x, float y);
sfVector2i vector2i_set(float x, float y);

int sort_by_order_layer(void *a, void *b);
#endif