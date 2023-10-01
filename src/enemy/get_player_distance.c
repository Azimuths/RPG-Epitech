/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_player_distance
*/

#include "rpg.h"
#include "player.h"
#include "math.h"

float get_player_distance(game_t *game, sfVector2f pos)
{
    float dest = 0;

    dest = (game->player->pos.x - pos.x) * (game->player->pos.x - pos.x);
    dest += (game->player->pos.y - pos.y) * (game->player->pos.y - pos.y);
    return sqrtf(dest);
}

sfVector2f get_player_vector(game_t *game, sfVector2f pos)
{
    sfVector2f dest = {0};

    dest.x = (game->player->pos.x - pos.x);
    dest.y = (game->player->pos.y - pos.y);
    return dest;
}
