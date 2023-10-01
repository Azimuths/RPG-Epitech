/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** lich_boss_summon
*/

#include "enemy.h"
#include "rpg.h"
#include "stdlib.h"

void lich_boss_summon(game_t *game)
{
    for (int i = 0; i < 4; ++i) {
        add_node(create_enemy(game, rand() % 3, ((sfVector2f){rand() % 1000
        + 1000, rand() % 1000})), &(game->enemies));
    }
}
