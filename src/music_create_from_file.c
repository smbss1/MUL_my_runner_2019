/*
** EPITECH PROJECT, 2019
** create_music
** File description:
** music creation
*/
#include <SFML/Audio.h>
#include <stdlib.h>
#include "entity.h"

music_t *music_create_from_file(const char *filepath)
{
    music_t *tmp = (music_t *)malloc(sizeof(music_t));
    tmp->buffer = sfSoundBuffer_createFromFile(filepath);
    tmp->sound = sfSound_create();
    sfSound_setBuffer(tmp->sound, tmp->buffer);
    return (tmp);
}