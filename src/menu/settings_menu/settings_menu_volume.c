/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** settings_menu_volume
*/

#include "rpg.h"
#include "sounds.h"
#include <stdlib.h>

void set_volume_down(game_t *game)
{
    char *volume = NULL;

    if (game->volume <= 0)
        return;
    game->volume -= 5;
    volume = int_to_str(game->volume);
    set_volume_off(game);
    sfText_setString(game->text->volume_nb->text, volume);
    free(volume);
}

void set_volume_up(game_t *game)
{
    char *volume = NULL;

    if (game->volume >= 100)
        return;
    game->volume += 5;
    volume = int_to_str(game->volume);
    set_volume_on(game);
    sfText_setString(game->text->volume_nb->text, volume);
    free(volume);
}
