/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_screen
*/

#include "rpg.h"
#include "my.h"
#include "rpg.h"
#include "particle.h"
#include "projectile.h"
#include "enemy.h"
#include "sounds.h"
#include "inventory.h"

static void update_game(game_t *game)
{
    update_particles(game);
    update_projectiles(game, &(game->projectiles));
}

static void animate_end_game(game_t *game)
{
    draw_particles(game);
    draw_projectiles(game, &(game->projectiles));
    sfClock_restart(game->clock_anim);
}

static void analyse_start_menu_events(game_t *game, sfClock *clock)
{
    if (game->event.type == sfEvtClosed) {
        game->screen = EXIT;
        sfRenderWindow_close(game->window);
    }
    if (game->event.type == sfEvtMouseButtonPressed ||
            get_time(clock, 5)) {
        game->screen = MAIN_MENU;
        destroy_particles(game);
        destroy_projectiles(game, &(game->projectiles));
    }
    analyse_mouse(game);
}

int start_screen(game_t *game)
{
    sfClock *clock = sfClock_create();

    add_node(create_end_screen_fire_duck(game), &(game->projectiles));
    add_node(create_end_screen_water_duck(game), &(game->projectiles));
    add_node(create_end_screen_rock_duck(game), &(game->projectiles));
    add_node(create_end_screen_ice_duck(game), &(game->projectiles));
    while (game->screen == START_SCREEN) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_start_menu_events(game, clock);
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
            sfRenderWindow_clear(game->window, sfBlack);
            update_game(game);
            animate_end_game(game);
        }
        sfRenderWindow_display(game->window);
    }
    sfClock_destroy(clock);
    return 0;
}
