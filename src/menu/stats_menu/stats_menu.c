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
        button_check_stats_menu(game);
    return;
}

int stats_menu(game_t *game)
{
    while (game->screen == STATS_MENU) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
        sfRenderWindow_clear(game->window, sfBlack);
            draw_stats_menu(game);
            draw_text_stats(game);
            update_health_point(game);
            update_attack_point(game);
            update_speed_point(game);
        }
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
