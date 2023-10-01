/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** menu
*/

#include "rpg.h"
#include "sounds.h"
#include "macro.h"

static void analyse_events(game_t *game)
{
    if (game->event.type == sfEvtClosed) {
        game->screen = EXIT;
        sfRenderWindow_close(game->window);
    }
    if (game->event.type == sfEvtMouseButtonPressed)
        button_check_pause_settings_menu(game);
    return;
}

int pause_settings_menu(game_t *game)
{
    while (game->screen == PAUSE_SETTINGS) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_pause_settings_menu(game);
        draw_pause_text_settings(game);
        }
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
