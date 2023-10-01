/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** on_click_skill_health_func
*/

#include "rpg.h"
#include "skill_tree.h"
#include "player.h"

void on_click_skill_health_first(game_t *game)
{
    if (game->skill_tree->health_level == 0 && game->skill_points > 0) {
        game->skill_tree->health_level = 1;
        game->skill_points--;
        game->player->max_hp += 500;
        game->player->hp += 500;
        sfSprite_setColor(game->skill->button_health_one->sprite, sfBlue);
    }
}

void on_click_skill_health_second(game_t *game)
{
    if (game->skill_tree->health_level == 1 && game->skill_points > 0) {
        game->skill_tree->health_level = 2;
        game->skill_points--;
        game->player->max_hp += 500;
        game->player->hp += 500;
        sfSprite_setColor(game->skill->button_health_two->sprite, sfBlue);
    }
}

void on_click_skill_health_third(game_t *game)
{
    if (game->skill_tree->health_level == 2 && game->skill_points > 0) {
        game->skill_tree->health_level = 3;
        game->skill_points--;
        game->player->max_hp += 500;
        game->player->hp += 500;
        sfSprite_setColor(game->skill->button_health_three->sprite, sfBlue);
    }
}
