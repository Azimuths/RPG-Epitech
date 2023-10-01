/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** boss_menu
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
    move_player_home(game);
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
}

void animate_boss_game(game_t *game)
{
    sfRenderWindow_setView(game->window, game->game_view);
    draw_player(game);
    draw_projectiles(game, &(game->projectiles));
    draw_projectiles(game, &(game->enemy_proj));
    draw_enemies(game);
    draw_particles(game);
    check_collisions_projectile(game);
    check_collisions_enemy_projectile(game);
    draw_inventory(game);
    sfClock_restart(game->clock_anim);
}

static void analyse_events(game_t *game)
{
    if (game->event.type == sfEvtClosed) {
        game->screen = EXIT;
        sfRenderWindow_close(game->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        if (game->screen == BOSS_MENU)
            game->screen = PAUSE;
    update_inventory(game->inventory, game->event);
    analyse_mouse(game);
    check_game_condition(game);
}

int boss_game(game_t *game)
{
    add_node(create_lich_boss(game), &(game->enemies));
    while (game->screen == BOSS_MENU) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        if (sfClock_getElapsedTime(game->clock_anim).microseconds > 32000) {
            sfRenderWindow_clear(game->window, sfBlack);
            draw_home_map(game);
            update_game(game);
            animate_boss_game(game);
            calculate_framerate(game);
            sfRenderWindow_display(game->window);
        }
    }
    return 0;
}
