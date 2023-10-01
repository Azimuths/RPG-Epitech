/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** check_death
*/

#include "rpg.h"
#include "player.h"

int check_death(game_t *game)
{
    static int time_elapsed = 0;

    if (game->player->hp < 0) {
        if (game->player->status != PLAYER_DEAD)
            game->player->status = PLAYER_DEAD;
        time_elapsed++;
    }
    if (time_elapsed > 300) {
        game->screen = MAIN_MENU;
        time_elapsed = 0;
    }
    return 0;
}
