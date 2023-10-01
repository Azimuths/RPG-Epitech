/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** game
*/

#include "my.h"
#include "rpg.h"
#include "particle.h"
#include "projectile.h"
#include "enemy.h"
#include "sounds.h"
#include "collectable.h"
#include "inventory.h"

static void update_game(game_t *game)
{
    check_collisions_projectile(game);
    check_collisions_enemy_projectile(game);
    check_collision_collectable(game);
    update_weather(game);
    move_player(game);
    if ((sfClock_getElapsedTime(game->clock_game).microseconds > 1000000)) {
        update_date(game);
        sfClock_restart(game->clock_game);
    }
    change_dir(game);
    change_speed(game);
    update_particles(game);
    update_enemies(game);
    update_projectiles(game, &(game->projectiles));
    update_projectiles(game, &(game->enemy_proj));
    update_collectable(game);
    switch_to_boss(game);
    move_view(game);
}

void animate_main_game(game_t *game)
{
    sfRenderWindow_setView(game->window, game->map->view);
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sfRenderWindow_setView(game->window, game->game_view);
    draw_particles(game);
    draw_player(game);
    draw_enemies(game);
    draw_projectiles(game, &(game->projectiles));
    draw_projectiles(game, &(game->enemy_proj));
    draw_collectables(game);
    check_collisions_projectile(game);
    check_collisions_enemy_projectile(game);
    check_collision_collectable(game);
    put_filter(game);
    draw_inventory(game);
    draw_fps(game);
    sfClock_restart(game->clock_anim);
}

void analyse_main_game_events(game_t *game)
{
    analyse_keyboard(game);
    analyse_mouse(game);
    check_game_condition(game);
}

int gameloop(game_t *game)
{
    spawn_entity(game);
    while (game->screen == GAME) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_main_game_events(game);
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
            sfRenderWindow_clear(game->window, sfBlack);
            update_game(game);
            animate_main_game(game);
        }
        calculate_framerate(game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
