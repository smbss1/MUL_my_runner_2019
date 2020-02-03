/*
** EPITECH PROJECT, 2019
** animation_system
** File description:
** Animation
*/

#include "game.h"
float dur;

void init_animation_system(sfClock **clock, float duration)
{
    *clock = sfClock_create();
    dur = duration;
}

void play_animation(sfIntRect *rec, sfClock *clock, double duration, int count)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds >= duration) {
        move_rect(rec, rec->width, count);
        sfClock_restart(clock);
    }
}

void play_animation_grid(sfIntRect *rec, sfClock *clock,
                                        double duration,
                                        sfVector2i grid)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds >= duration) {
        move_rect_grid(rec, rec->width, grid);
        sfClock_restart(clock);
    }
}

int play_animation_once(sfIntRect *rec, sfClock *clock,
                                        double duration,
                                        int count)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);
    int anim_finished = 0;

    if (seconds > duration && anim_finished == 0) {
        anim_finished = move_rect(rec, rec->width, count);
        sfClock_restart(clock);
    }
    return (anim_finished);
}