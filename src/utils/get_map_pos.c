/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_map_pos
*/

#include "rpg.h"

int get_map_pos(game_t *game, sfVector2f pos)
{
    int dest = (((int)((pos.y / 96) + (int)(game->map->screen_pos.y * 11)
    )) * 60) +
            ((int)((pos.x / 96) + (int)(game->map->screen_pos.x * 20)));

    return dest;
}
