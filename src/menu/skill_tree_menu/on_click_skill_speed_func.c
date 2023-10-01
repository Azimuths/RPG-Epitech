/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** on_click_skill_speed_func
*/

#include "rpg.h"
#include "skill_tree.h"
#include "player.h"

void on_click_skill_speed_first(game_t *game)
{
    if (game->skill_tree->velocity_level == 0 && game->skill_points > 0) {
        game->skill_tree->velocity_level = 1;
        game->skill_points--;
        game->player->spd += 1;
        sfSprite_setColor(game->skill->button_speed_one->sprite, sfGreen);
    }
}

void on_click_skill_speed_second(game_t *game)
{
    if (game->skill_tree->velocity_level == 1 && game->skill_points > 0) {
        game->skill_tree->velocity_level = 2;
        game->skill_points--;
        game->player->spd += 1;
        sfSprite_setColor(game->skill->button_speed_two->sprite, sfGreen);
    }
}

void on_click_skill_speed_third(game_t *game)
{
    if (game->skill_tree->velocity_level == 2 && game->skill_points > 0) {
        game->skill_tree->velocity_level = 3;
        game->skill_points--;
        game->player->spd += 1;
        sfSprite_setColor(game->skill->button_speed_three->sprite, sfGreen);
    }
}
