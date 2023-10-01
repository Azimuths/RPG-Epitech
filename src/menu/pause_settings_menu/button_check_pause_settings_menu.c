/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** button_check
*/

#include "rpg.h"
#include "sounds.h"
#include "macro.h"

void button_check_pause_settings_menu(game_t *game)
{
    object_t *button_array[] = {game->pause_settings->button_menu,
    game->pause_settings->button_plus, game->pause_settings->button_less,
    game->pause_settings->button_plus_two,
    game->pause_settings->button_less_two,
    game->pause_settings->button_left,
    game->pause_settings->button_right, NULL};
    sfFloatRect pos;

    for (int i = 0; button_array[i] != NULL; i++) {
        pos = sfSprite_getGlobalBounds(button_array[i]->sprite);
        if (sfFloatRect_contains(&pos, MOUSE_X, MOUSE_Y)) {
            return button_array[i]->on_click(game);
        }
    }
}

int init_button_pause_settings_menu(every_object_t *obj)
{
    obj->button_menu->on_click = switch_to_pause_menu;
    obj->button_plus->on_click = set_fps_up;
    obj->button_less->on_click = set_fps_down;
    obj->button_less_two->on_click = set_volume_down;
    obj->button_plus_two->on_click = set_volume_up;
    obj->button_left->on_click = set_render_window;
    obj->button_right->on_click = set_render_window;
    return 0;
}
