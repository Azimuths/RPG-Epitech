/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** on_keypress
*/

#include "rpg.h"
#include "player.h"
#include "projectile.h"
#include "sounds.h"

int check_attack(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
            game->player->status != PLAYER_ATTACKING) {
        sfSound_play(game->sounds->attack->sound);
        game->player->status = PLAYER_ATTACKING;
        game->player->rect.left = 0;
        attack_player(game);
    }
    return 0;
}

int change_dir(game_t *game)
{
    if (game->player->status == PLAYER_ATTACKING &&
    game->player->sword_rect.left != 0)
        return 0;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        game->player->dir = DOWN;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        game->player->dir = UP;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        game->player->dir = LEFT;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        game->player->dir = RIGHT;
    return 0;
}

int change_speed(game_t *game)
{
    check_attack(game);
    if (game->player->status == PLAYER_ATTACKING)
        return 0;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        game->player->velocity.y = 5 + game->player->spd;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        game->player->velocity.y = -5 - game->player->spd;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        game->player->velocity.x = -5 - game->player->spd;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        game->player->velocity.x = 5 + game->player->spd;
    return 0;
}
