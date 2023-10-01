/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** home_move_player
*/

#include "rpg.h"
#include "player.h"

int move_player_home(game_t *game)
{
    sfVector2f pos_buffer = game->player->pos;

    pos_buffer.x = game->player->pos.x + game->player->velocity.x;
    if (pos_buffer.x > 0 && pos_buffer.x < 1920)
        game->player->pos.x = pos_buffer.x;
    pos_buffer.x = game->player->pos.x;
    pos_buffer.y = game->player->pos.y + game->player->velocity.y;
    if (pos_buffer.y > 0 && pos_buffer.y < 1080)
        game->player->pos.y = pos_buffer.y;
    pos_buffer.y = game->player->pos.y;
    game->player->velocity.x *= 0.9;
    game->player->velocity.y *= 0.9;
    if (game->player->velocity.x > -1 && game->player->velocity.x < 1)
        game->player->velocity.x = 0;
    if (game->player->velocity.y > -1 && game->player->velocity.y < 1)
        game->player->velocity.y = 0;
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    return 0;
}
