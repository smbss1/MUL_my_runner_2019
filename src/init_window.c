/*
** EPITECH PROJECT, 2019
** init_window
** File description:
** Initialise Window
*/

#include "game.h"

void init_window(core_t *core)
{
    sfVideoMode video_mode = { SCREEN_WIDTH, SCREEN_HEIGHT, 32 };
    core->window = sfRenderWindow_create(video_mode, "My Runner",
                                            sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(core->window, 60);
}