/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** select_menu
*/

#include "rpg.h"

int select_menu(game_t *game)
{
    int (*change_menu[])(game_t *) = {main_menu, gameloop,
            pause_menu, settings_menu, htp_menu, pause_settings_menu,
            skill_menu, quest_menu, stats_menu, boss_game, editor, home_game,
            end_screen, start_screen};

    game->screen = START_SCREEN;
    while (game->screen != EXIT)
        change_menu[game->screen](game);
    return 0;
}
