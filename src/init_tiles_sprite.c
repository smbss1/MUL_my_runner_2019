/*
** EPITECH PROJECT, 2019
** init_tiles_sprite
** File description:
** Initialize all sprites for tiles
*/

#include "my.h"

void init_tiles_sprite(dictionary **tile_files)
{
    dictionary_add(tile_files, "1", "sprite/tile/1.png");
    dictionary_add(tile_files, "2", "sprite/tile/Trap 1.png");
    dictionary_add(tile_files, "o", "sprite/coins.png");
    dictionary_add(tile_files, "7", "sprite/tile/win.png");
}