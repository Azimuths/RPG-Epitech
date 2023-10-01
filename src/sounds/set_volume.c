/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** set_volume
*/

#include "rpg.h"
#include "sounds.h"

void set_volume_off(game_t *game)
{
    sfMusic_setVolume(game->sounds->music, game->volume);
    sfSound_setVolume(game->sounds->click->sound, game->volume);
}

void set_volume_on(game_t *game)
{
    sfMusic_setVolume(game->sounds->music, game->volume);
    sfSound_setVolume(game->sounds->click->sound, game->volume);
}
