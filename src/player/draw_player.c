/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_player
*/

#include "rpg.h"
#include "player.h"
#include "inventory.h"

int draw_player(game_t *game)
{
    sfVector2f sword_pos;

    if (get_time(game->player->clock, 0.1))
        animate_player(game->player);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    if (game->player->status == PLAYER_ATTACKING &&
game->inventory->contents[game->inventory->curr] == WEAPON_SWORD) {
        sword_pos = game->player->pos;
        sfSprite_setPosition(game->player->sword, sword_pos);
        sfSprite_setTextureRect(game->player->sword, game->player->sword_rect);
        sfRenderWindow_drawSprite(game->window, game->player->sword, NULL);
    }
    return 0;
}
