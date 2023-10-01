/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** move_player
*/

#include "player.h"

int move_player(game_t *game)
{
    sfVector2f pos_buffer = game->player->pos;

    pos_buffer.x = game->player->pos.x + game->player->velocity.x;
    if (!check_collision(game, pos_buffer))
        game->player->pos.x = pos_buffer.x;
    pos_buffer.x = game->player->pos.x;
    pos_buffer.y = game->player->pos.y + game->player->velocity.y;
    if (!check_collision(game, pos_buffer))
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
