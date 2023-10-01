/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_player_state
*/

#include "player.h"

int update_player_state(player_t *player)
{
    if (player->status == PLAYER_MOVING && player->velocity.x == 0 &&
            player->velocity.y == 0)
        player->status = PLAYER_IDLE;
    if (player->status == PLAYER_IDLE && (player->velocity.x != 0 ||
            player->velocity.y != 0))
        player->status = PLAYER_MOVING;
    return 0;
}
