/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** main_menu_func
*/

#include "rpg.h"
#include "sounds.h"
#include "macro.h"
#include <SFML/Graphics/RenderWindow.h>

void switch_to_main_menu(game_t *game)
{
    reset_game(game);
    change_music(game, MAIN_MUSIC);
    game->screen = MAIN_MENU;
}

void settings_to_main_menu(game_t *game)
{
    reset_game(game);
    game->screen = MAIN_MENU;
}

void set_render_window(game_t *game)
{
    if (game->win_size == 0) {
        sfRenderWindow_setSize(game->window, (sfVector2u){1920, 1080});
        game->mode.height = 1080;
        game->mode.width = 1920;
        sfText_setString(game->text->res_val->text, "1920x1080");
        game->win_size = 1;
        return;
    }
    if (game->win_size == 1) {
        sfRenderWindow_setSize(game->window, (sfVector2u){800, 600});
        game->mode.height = 600;
        game->mode.width = 800;
        sfText_setString(game->text->res_val->text, "800x600");
        game->win_size = 0;
        return;
    }
}

void set_fps_up(game_t *game)
{
    sfText_setString(game->text->set_fps->text, "60");
    sfRenderWindow_setFramerateLimit(game->window, 60);
}

void set_fps_down(game_t *game)
{
    sfText_setString(game->text->set_fps->text, "30");
    sfRenderWindow_setFramerateLimit(game->window, 30);

}
