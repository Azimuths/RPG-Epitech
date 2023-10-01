/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** window
*/

#include "rpg.h"
#include "macro.h"
#include "config.h"

int open_window(game_t *game)
{
    game->mode = game->config->videomode;
    game->window = sfRenderWindow_create(game->mode, "CARLOS Quest",
            sfClose, NULL);
    if (!game->window)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return 0;
}
