/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** button_check
*/

#include "rpg.h"
#include "sounds.h"
#include "macro.h"
#include "skill_tree.h"

void button_check_click_skill_menu(game_t *game)
{
    object_t *button_array[] = {game->skill->button_left_two,
    game->skill->button_dmg_one, game->skill->button_dmg_two,
    game->skill->button_dmg_three, game->skill->button_health_one,
    game->skill->button_health_two, game->skill->button_health_three,
    game->skill->button_speed_one, game->skill->button_speed_two,
    game->skill->button_speed_three, NULL};
    sfFloatRect pos;

    for (int i = 0; button_array[i] != NULL; i++) {
        pos = sfSprite_getGlobalBounds(button_array[i]->sprite);
        if (sfFloatRect_contains(&pos, MOUSE_X, MOUSE_Y)) {
            return button_array[i]->on_click(game);
        }
    }
}

void button_check_hover_skill_menu(game_t *game)
{
    object_t *button_array[] = {game->skill->button_dmg_one,
    game->skill->button_dmg_two, game->skill->button_dmg_three,
    game->skill->button_health_one, game->skill->button_health_two,
    game->skill->button_health_three, game->skill->button_speed_one,
    game->skill->button_speed_two, game->skill->button_speed_three, NULL};
    sfFloatRect pos;

    for (int i = 0; button_array[i] != NULL; i++) {
        pos = sfSprite_getGlobalBounds(button_array[i]->sprite);
        if (sfFloatRect_contains(&pos, HOVER_X, HOVER_Y)) {
            return button_array[i]->on_hover(game);
        }
    }
}

int init_button_hover_skill_menu(every_object_t *obj)
{
    obj->button_dmg_one->on_hover = show_text_dmg;
    obj->button_dmg_one->on_click = on_click_skill_atk_first;
    obj->button_dmg_two->on_hover = show_text_dmg;
    obj->button_dmg_two->on_click = on_click_skill_atk_second;
    obj->button_dmg_three->on_hover = show_text_dmg;
    obj->button_dmg_three->on_click = on_click_skill_atk_third;
    obj->button_health_one->on_hover = show_text_health;
    obj->button_health_one->on_click = on_click_skill_health_first;
    obj->button_health_two->on_hover = show_text_health;
    obj->button_health_two->on_click = on_click_skill_health_second;
    obj->button_health_three->on_hover = show_text_health;
    obj->button_health_three->on_click = on_click_skill_health_third;
    obj->button_speed_one->on_hover = show_text_speed;
    obj->button_speed_one->on_click = on_click_skill_speed_first;
    obj->button_speed_two->on_hover = show_text_speed;
    obj->button_speed_two->on_click = on_click_skill_speed_second;
    obj->button_speed_three->on_hover = show_text_speed;
    obj->button_speed_three->on_click = on_click_skill_speed_third;
    return 0;
}

int init_button_click_skill_menu(every_object_t *obj)
{
    obj->button_left_two->on_click = switch_to_game;
    return 0;
}
