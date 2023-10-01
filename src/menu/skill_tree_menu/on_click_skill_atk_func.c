/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** on_click_skill_atk_func
*/


#include "rpg.h"
#include "skill_tree.h"
#include "player.h"

void on_click_skill_atk_first(game_t *game)
{
    if (game->skill_tree->attack_level == 0 && game->skill_points > 0) {
        game->skill_tree->attack_level = 1;
        game->skill_points--;
        game->player->dmg += 10;
        sfSprite_setColor(game->skill->button_dmg_one->sprite, sfRed);
    }
}

void on_click_skill_atk_second(game_t *game)
{
    if (game->skill_tree->attack_level == 1 && game->skill_points > 0) {
        game->skill_tree->attack_level = 2;
        game->skill_points--;
        game->player->dmg += 10;
        sfSprite_setColor(game->skill->button_dmg_two->sprite, sfRed);
    }
}

void on_click_skill_atk_third(game_t *game)
{
    if (game->skill_tree->attack_level == 2 && game->skill_points > 0) {
        game->skill_tree->attack_level = 3;
        game->skill_points--;
        game->player->dmg += 10;
        sfSprite_setColor(game->skill->button_dmg_three->sprite, sfRed);
    }
}
