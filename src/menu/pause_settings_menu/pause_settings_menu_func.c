/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** pause_settings_menu_func
*/

#include "rpg.h"

void switch_to_pause_settings_menu(game_t *game)
{
    game->screen = PAUSE_SETTINGS;
}

void switch_to_pause_menu(game_t *game)
{
    game->screen = PAUSE;
}
