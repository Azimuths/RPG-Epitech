/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** button_check
*/

#include "rpg.h"
#include "sounds.h"
#include "macro.h"

void button_check_quest_menu(game_t *game)
{
    object_t *button_array[] = {game->skill->button_left_two, NULL};
    sfFloatRect pos;

    for (int i = 0; button_array[i] != NULL; i++) {
        pos = sfSprite_getGlobalBounds(button_array[i]->sprite);
        if (sfFloatRect_contains(&pos, MOUSE_X, MOUSE_Y)) {
            return button_array[i]->on_click(game);
        }
    }
}

void init_button_quest_menu(every_object_t *obj)
{
    obj->button_left_two->on_click = switch_to_game;
}
