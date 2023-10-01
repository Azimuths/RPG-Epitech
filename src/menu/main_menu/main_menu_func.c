/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** main_menu_func
*/

#include "rpg.h"
#include "sounds.h"
#include "macro.h"

void switch_to_game(game_t *game)
{
    game->screen = GAME;
}

void main_menu_to_game(game_t *game)
{
    sfView_destroy(game->map->view);
    game->map->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    change_music(game, GAME_MUSIC);
    game->screen = HOME_GAME;
}

void exit_game(game_t *game)
{
    game->screen = EXIT;
}

void switch_to_settings_menu(game_t *game)
{
    game->screen = OPTION;
}

void switch_to_htp_menu(game_t *game)
{
    game->screen = HTP_MENU;
}
