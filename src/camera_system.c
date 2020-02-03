/*
** EPITECH PROJECT, 2019
** camera_system
** File description:
** Manage the camera
*/

#include "game.h"

float lerp(float a, float b, float f);

void init_camera(core_t *core)
{
    if (core)
        core->view = sfRenderWindow_getView(core->window);
}

void update_camera(entity_t *player, float dt, core_t *core)
{
    float desiredPosX = player->position.x + 0;
    float desiredPosY = player->position.y + 60;
    float smoothPosX = lerp(sfView_getCenter(core->view).x,
                                        desiredPosX, 0.07f);
    float smoothPosY = lerp(sfView_getCenter(core->view).y,
                                        desiredPosY, 0.075f);
    sfVector2f smoothedPosition = vector2f_set(smoothPosX, desiredPosY);
    if (smoothedPosition.y <= 530)
        smoothedPosition.y = 530;
    if (smoothedPosition.y >= 580)
        smoothedPosition.y = 580;
    if (smoothedPosition.x <= 995)
        smoothedPosition.x = 995;
    sfView_setCenter(core->view, smoothedPosition);
}