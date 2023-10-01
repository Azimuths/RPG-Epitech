/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** menu
*/

#include "rpg.h"
#include "sounds.h"
#include "macro.h"

static void analyse_htp_events(game_t *game)
{
    if (game->event.type == sfEvtClosed) {
        game->screen = EXIT;
        sfRenderWindow_close(game->window);
    }
    if (game->event.type == sfEvtMouseButtonPressed)
        button_check_settings_menu(game);
    return;
}

int htp_menu(game_t *game)
{
    while (game->screen == HTP_MENU) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_map_scrolling(game);
        draw_htp_menu(game);
        }
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_htp_events(game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
