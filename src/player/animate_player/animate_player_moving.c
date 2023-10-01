/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** animate_player_moving
*/

#include "rpg.h"
#include "player.h"

int animate_player_moving(player_t *player)
{
    player->rect.top = 48 * (player->dir + 4);
    player->rect.left += 48;
    if (player->rect.left > 132)
        player->rect.left = 0;
    return 0;
}
