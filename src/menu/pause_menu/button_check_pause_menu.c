/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** button_check
*/

#include "rpg.h"
#include "macro.h"
#include "sounds.h"

void button_check_pause_menu(game_t *game)
{
    object_t *button_array[] = {game->pause->button_resume,
    game->pause->button_menu, game->pause->button_door,
    game->pause->button_option, NULL};
    sfFloatRect pos;

    for (int i = 0; button_array[i] != NULL; i++) {
        pos = sfSprite_getGlobalBounds(button_array[i]->sprite);
        if (sfFloatRect_contains(&pos, MOUSE_X, MOUSE_Y)) {
            return button_array[i]->on_click(game);
        }
    }
}

int init_button_pause_menu(every_object_t *obj)
{
    obj->button_resume->on_click = switch_to_game;
    obj->button_menu->on_click = switch_to_main_menu;
    obj->button_door->on_click = exit_game;
    obj->button_option->on_click = switch_to_pause_settings_menu;
    return 0;
}
