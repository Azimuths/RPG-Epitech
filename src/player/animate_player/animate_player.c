/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** animate_player
*/

#include "rpg.h"
#include "player.h"

int animate_player(player_t *player)
{
    update_player_state(player);
    switch (player->status) {
        case PLAYER_IDLE:
            animate_player_idle(player);
            break;
        case PLAYER_MOVING:
            animate_player_moving(player);
            break;
        case PLAYER_ATTACKING:
            animate_player_attacking(player);
            break;
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
    return 0;
}
