/*
** EPITECH PROJECT, 2019
** create_text
** File description:
** Create a new sfText and return a pointer of this struct
*/

#include "game.h"

sfText *create_text(char *str, sfFont *font, unsigned int size)
{
    sfText *text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    return (text);
}