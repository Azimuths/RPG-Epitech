/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** skill_menu_func
*/

#include "rpg.h"
#include "macro.h"

void show_text_dmg(game_t *game)
{
    sfText_setString(game->skill_text->skill->text, DMG_TEXT);
    return;
}

void show_text_health(game_t *game)
{
    sfText_setString(game->skill_text->skill->text, HEALTH_TEXT);
    return;
}

void show_text_speed(game_t *game)
{
    sfText_setString(game->skill_text->skill->text, SPEED_TEXT);
    return;
}
