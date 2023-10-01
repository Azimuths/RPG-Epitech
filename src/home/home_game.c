/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** home_game
*/

#include "rpg.h"
#include "projectile.h"
#include "particle.h"
#include "inventory.h"

static void update_home_game(game_t *game)
{
    check_collisions_projectile(game);
    check_collisions_enemy_projectile(game);
    move_player_home(game);
    if ((sfClock_getElapsedTime(game->clock_game).microseconds > 1000000)) {
        update_date(game);
        sfClock_restart(game->clock_game);
    }
    change_dir(game);
    change_speed(game);
    update_particles(game);
    update_projectiles(game, &(game->projectiles));
    update_projectiles(game, &(game->enemy_proj));
}

void animate_home_game(game_t *game)
{
    sfRenderWindow_setView(game->window, game->map->view);
    draw_home_map(game);
    sfRenderWindow_setView(game->window, game->game_view);
    draw_particles(game);
    draw_player(game);
    draw_projectiles(game, &(game->projectiles));
    draw_projectiles(game, &(game->enemy_proj));
    draw_inventory(game);
    check_home_exit(game);
    draw_fps(game);
    sfClock_restart(game->clock_anim);
}

static void analyse_events(game_t *game)
{
    analyse_keyboard(game);
    analyse_mouse(game);
}

int home_game(game_t *game)
{
    game->weather = CLEAR;
    while (game->screen == HOME_GAME) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
            sfRenderWindow_clear(game->window, sfBlack);
            update_home_game(game);
            animate_home_game(game);
        }
        calculate_framerate(game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
