/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** init_main_menu
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

int init_skill_menu(every_object_t *obj)
{
    if (!(obj->button_left_two = create_object(BUTTON_LEFT, ((sfIntRect)
    {0, 0, 500, 350}), ((sfVector2f){100, 100}), ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->ux_bg = create_object(UX_BG,
    ((sfIntRect){0, 0, 965, 623}), ((sfVector2f){950, 450}),
    ((sfVector2f){1.2, 1.2}))))
        return 84;
    if (!(obj->ux_bg_little = create_object(UX_BG,
    ((sfIntRect){0, 0, 965, 623}), ((sfVector2f){950, 900}),
    ((sfVector2f){0.3, 0.25}))))
        return 84;
    if (!(obj->ux_win_four = create_object(UX_BG,
    ((sfIntRect){0, 0, 965, 623}), ((sfVector2f){1720, 400}),
    ((sfVector2f){0.25, 0.25}))))
        return 84;
    sprite_set_center(obj->button_left_two->sprite);
    sprite_set_center(obj->ux_bg->sprite);
    sprite_set_center(obj->ux_win_four->sprite);
    sprite_set_center(obj->ux_bg_little->sprite);
    return 0;
}

int init_skill_menu_third(every_object_t *obj)
{
    if (!(obj->background = create_object(MAP,
    ((sfIntRect){0, 0, 2400, 1850}), ((sfVector2f){984, 500}),
    ((sfVector2f){1, 1}))))
        return 84;
    sprite_set_center(obj->background->sprite);
    return 0;
}

int init_skill_menu_four(every_object_t *obj)
{
    if (!(obj->ux_win_three = create_object(UX_WINDOW,
    ((sfIntRect){0, 0, 180, 735}), ((sfVector2f){700, 450}),
    ((sfVector2f){0.85, 0.85}))))
        return 84;
    sprite_set_center(obj->ux_win_three->sprite);
    return 0;
}

every_object_t *init_skill_menu_second(void)
{
    every_object_t *obj = (every_object_t *)malloc(sizeof(every_object_t));

    if (!(obj->ux_win_one = create_object(UX_WINDOW,
    ((sfIntRect){0, 0, 180, 735}), ((sfVector2f){950, 450}),
    ((sfVector2f){0.85, 0.85}))))
        return NULL;
    if (!(obj->ux_win_two = create_object(UX_WINDOW,
    ((sfIntRect){0, 0, 180, 735}), ((sfVector2f){1200, 450}),
    ((sfVector2f){0.85, 0.85}))))
        return NULL;
    if (init_skill_menu(obj) == 84 || init_skill_menu_third(obj) == 84 ||
        init_skill_button_damage(obj) == 84 ||
        init_skill_button_health(obj) == 84 ||
        init_skill_button_speed(obj) == 84 || init_skill_menu_four(obj) == 84)
        return NULL;
    init_button_hover_skill_menu(obj);
    init_button_click_skill_menu(obj);
    sprite_set_center(obj->ux_win_one->sprite);
    sprite_set_center(obj->ux_win_two->sprite);
    return obj;
}

void draw_skill_menu(game_t *game)
{
    draw_object(game->skill->background, game);
    draw_object(game->skill->ux_bg, game);
    draw_object(game->skill->ux_bg_little, game);
    draw_object(game->skill->ux_win_four, game);
    draw_object(game->skill->ux_win_one, game);
    draw_object(game->skill->ux_win_two, game);
    draw_object(game->skill->ux_win_three, game);
    draw_object(game->skill->button_left_two, game);
    draw_object(game->skill->button_dmg_one, game);
    draw_object(game->skill->button_dmg_two, game);
    draw_object(game->skill->button_dmg_three, game);
    draw_object(game->skill->button_health_one, game);
    draw_object(game->skill->button_health_two, game);
    draw_object(game->skill->button_health_three, game);
    draw_object(game->skill->button_speed_one, game);
    draw_object(game->skill->button_speed_two, game);
    draw_object(game->skill->button_speed_three, game);
}
