/*
** EPITECH PROJECT, 2019
** game_over
** File description:
** end of the game
*/

#include "scene.h"

int game_over(core_t *core)
{
    my_printf("GAME OVER\n");
    core->exit = 0;
    return (0);
}

void player_win(core_t *core)
{
    core->exit = 0;
    my_printf("Player Win\n");
}