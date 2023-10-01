/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** move_view
*/

#include "rpg.h"
#include "player.h"

void move_view(game_t *game)
{
    if (game->player->pos.x >= 1920) {
        return scroll_view_right(game, (sfVector2f){1920, 0});
    }
    if (game->player->pos.y >= 1080) {
        return scroll_view_down(game, (sfVector2f){0, 1080});
    }
    if (game->player->pos.x <= 0) {
        return scroll_view_left(game, (sfVector2f){-1920, 0});
    }
    if (game->player->pos.y <= 0) {
        return scroll_view_up(game, (sfVector2f){0, -1080});
    }
}
