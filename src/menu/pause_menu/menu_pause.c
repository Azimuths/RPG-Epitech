/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** menu.pause
*/

#include "rpg.h"
#include "sounds.h"

static void analyse_events(game_t *game)
{
    if (game->event.type == sfEvtClosed) {
        game->screen = EXIT;
        sfRenderWindow_close(game->window);
    }
    if (game->event.type == sfEvtMouseButtonPressed)
        button_check_pause_menu(game);
    return;
}

int pause_menu(game_t *game)
{
    while (game->screen == PAUSE) {
        sfRenderWindow_clear(game->window, sfBlack);
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        draw_pause_menu(game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
