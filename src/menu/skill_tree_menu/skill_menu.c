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
        button_check_click_skill_menu(game);
    button_check_hover_skill_menu(game);
    return;
}

int skill_menu(game_t *game)
{
    update_skill_point(game);
    while (game->screen == SKILL_TREE) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
        sfRenderWindow_clear(game->window, sfBlack);
            draw_skill_menu(game);
            draw_text_skill(game);
        }
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
