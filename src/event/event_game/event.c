/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** event
*/

#include "rpg.h"
#include "particle.h"
#include "projectile.h"
#include "enemy.h"
#include "inventory.h"
#include "sounds.h"

void analyse_keyboard(game_t *game)
{
    if (game->event.type == sfEvtClosed) {
        game->screen = EXIT;
        sfRenderWindow_close(game->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        if (game->screen == GAME)
            game->screen = PAUSE;
    if (sfKeyboard_isKeyPressed(sfKeyH))
        if (game->screen == GAME)
            game->screen = SKILL_TREE;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        if (game->screen == GAME)
            game->screen = STATS_MENU;
    if (sfKeyboard_isKeyPressed(sfKeyX))
        if (game->screen == GAME)
            game->screen = QUEST_MENU;
    move_view(game);
    update_inventory(game->inventory, game->event);
}

void analyse_mouse(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed)
        sfSound_play(game->sounds->click->sound);
    if (game->event.type == sfEvtMouseButtonPressed)
        for (int i = 0; i < 10; ++i)
            add_node(create_star_particle(game), &(game->particles));
}

void check_game_condition(game_t *game)
{
    if (game->player->hp <= 0) {
        game->screen = MAIN_MENU;
        reset_game(game);
    }
}
