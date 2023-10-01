/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** menu
*/

#include "rpg.h"
#include "sounds.h"
#include "macro.h"

void draw_map_scrolling(game_t *game)
{
    static int move = 1;

    sfRenderWindow_setView(game->window, game->map->view);
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sfView_move(game->map->view, game->map->offset);
    game->map->pos.x += 15 * move;
    game->map->pos.y += 10 * move;
    if ((game->map->pos.x >= WIDTH * 1.5 && game->map->pos.y >= HEIGHT * 1.5)
    || (game->map->pos.x <= 0 && game->map->pos.y <= 0)) {
        move *= -1;
        game->map->offset.x *= -1;
        game->map->offset.y *= -1;
    }
    sfClock_restart(game->clock_anim);
    sfRenderWindow_setView(game->window, game->game_view);
}

static void analyse_events(game_t *game)
{
    if (game->event.type == sfEvtClosed) {
        game->screen = EXIT;
        sfRenderWindow_close(game->window);
    }
    if (game->event.type == sfEvtMouseButtonPressed)
        button_check_main_menu(game);
    return;
}

int main_menu(game_t *game)
{
    while (game->screen == MAIN_MENU) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
            sfRenderWindow_clear(game->window, sfBlack);
            draw_map_scrolling(game);
            draw_main_menu(game);
        }
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
