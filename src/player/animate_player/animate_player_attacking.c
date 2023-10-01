/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** animate_player_attacking
*/

#include "rpg.h"
#include "player.h"

int animate_player_attacking(player_t *player)
{
    player->rect.top = 48 * (player->dir + 8);
    player->rect.left += 48;
    if (player->rect.left > 144) {
        player->rect.left -= 48;
    }
    player->sword_rect.top = (player->dir) * 144;
    player->sword_rect.left += 144;
    if (player->sword_rect.left > 144 * 3) {
        player->sword_rect.left = -144;
        player->status = PLAYER_IDLE;
    }
    return 0;
}
