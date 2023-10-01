/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** button_check
*/

#include "rpg.h"
#include "macro.h"
#include "sounds.h"

void button_check_main_menu(game_t *game)
{
    object_t *button_array[] = {game->all_obj->button_play,
    game->all_obj->button_exit, game->all_obj->button_option,
    game->all_obj->button_htp, game->all_obj->button_editor, NULL};
    sfFloatRect pos;

    for (int i = 0; button_array[i] != NULL; i++) {
        pos = sfSprite_getGlobalBounds(button_array[i]->sprite);
        if (sfFloatRect_contains(&pos, MOUSE_X, MOUSE_Y)) {
            return button_array[i]->on_click(game);
        }
    }
}

int init_button_main_menu(every_object_t *obj)
{
    obj->button_editor->on_click = switch_to_editor;
    obj->button_play->on_click = main_menu_to_game;
    obj->button_exit->on_click = exit_game;
    obj->button_option->on_click = switch_to_settings_menu;
    obj->button_htp->on_click = switch_to_htp_menu;
    return 0;
}
