/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** change_music
*/

#include "sounds.h"
#include "rpg.h"

void change_music(game_t *game, char *filename)
{
    sfMusic_stop(game->sounds->music);
    sfMusic_destroy(game->sounds->music);
    game->sounds->music = create_music(filename, game->volume);
}
