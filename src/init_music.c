/*
** EPITECH PROJECT, 2019
** init_music
** File description:
** init music
*/

#include "scene.h"

void init_music(core_t *core)
{
    core->main_music.sound = sfSound_create();
    core->main_music.buffer =
                        sfSoundBuffer_createFromFile("sounds/main_music.ogg");
    sfSound_setBuffer(core->main_music.sound,
                    core->main_music.buffer);
    core->jump_sound.sound = sfSound_create();
    core->jump_sound.buffer =
                        sfSoundBuffer_createFromFile("sounds/jump.ogg");
    sfSound_setBuffer(core->jump_sound.sound,
                    core->jump_sound.buffer);
}

void init_score_text(core_t *core)
{
    core->font = sfFont_createFromFile("arial.ttf");
    core->scoretxt = sfText_create();
    sfText_setFont(core->scoretxt, core->font);
    sfText_setCharacterSize(core->scoretxt, 30);
    sfText_setColor(core->scoretxt, sfColor_fromRGB(255, 150, 150));
}