/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** View scrolling function
*/

#include "rpg.h"
#include "projectile.h"
#include "particle.h"
#include "enemy.h"

void animate_scroll(game_t *game)
{
    if (sfClock_getElapsedTime(game->clock_anim).microseconds > 14000) {
        sfRenderWindow_clear(game->window, sfWhite);
        sfRenderWindow_setView(game->window, game->map->view);
        sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
        sfRenderWindow_setView(game->window, game->game_view);
        draw_player(game);
        put_filter(game);
        sfClock_restart(game->clock_anim);
        sfRenderWindow_display(game->window);
    }
}

void scroll_view_right(game_t *game, sfVector2f mov)
{
    int travel = 0;

    clear_screen(game);
    game->map->screen_pos.x++;
    while (travel < mov.x) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 14000) {
            travel += VIEW_MOVE;
            sfView_move(game->map->view, (sfVector2f){VIEW_MOVE, 0});
            game->player->pos.x -= VIEW_MOVE;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
            animate_scroll(game);
        }
        sfRenderWindow_display(game->window);
    }
    game->player->pos.x = 10;
    spawn_entity(game);
}

void scroll_view_down(game_t *game, sfVector2f mov)
{
    int travel = 0;

    clear_screen(game);
    game->map->screen_pos.y++;
    while (travel < mov.y) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 14000) {
            travel += VIEW_MOVE;
            sfView_move(game->map->view, (sfVector2f){0, VIEW_MOVE});
            game->player->pos.y -= VIEW_MOVE;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
            animate_scroll(game);
        }
        sfRenderWindow_display(game->window);
    }
    sfView_move(game->map->view, (sfVector2f){0, (float)(-24)});
    game->player->pos.y = 10;
    spawn_entity(game);
}

void scroll_view_left(game_t *game, sfVector2f mov)
{
    int travel = 0;

    clear_screen(game);
    game->map->screen_pos.x--;
    while (travel > mov.x) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 14000) {
            travel -= VIEW_MOVE;
            sfView_move(game->map->view, (sfVector2f){-VIEW_MOVE, 0});
            game->player->pos.x += VIEW_MOVE;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
            animate_scroll(game);
        }
        sfRenderWindow_display(game->window);
    }
    game->player->pos.x = 1910;
    spawn_entity(game);
}

void scroll_view_up(game_t *game, sfVector2f mov)
{
    int travel = 0;

    clear_screen(game);
    game->map->screen_pos.y--;
    while (travel > mov.y) {
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 14000) {
            travel -= VIEW_MOVE;
            sfView_move(game->map->view, (sfVector2f){0, -VIEW_MOVE});
            game->player->pos.y += VIEW_MOVE;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
            animate_scroll(game);
        }
        sfRenderWindow_display(game->window);
    }
    sfView_move(game->map->view, (sfVector2f){0, (float)(24)});
    game->player->pos.y = 1070;
    spawn_entity(game);
}
