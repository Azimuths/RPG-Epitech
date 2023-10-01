/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** lich_boss_update
*/

#include "enemy.h"

int lich_boss_animate(game_t *game, enemy_t *enemy)
{
    switch (enemy->status) {
        case ENEMY_IDLE:
            lich_boss_idle(game, enemy);
            break;
        case ENEMY_ATTACKING:
            lich_boss_attacking(game, enemy);
            break;
        case ENEMY_SUMMON:
            lich_boss_summoning(game, enemy);
            break;
        case ENEMY_CASTING:
            lich_boss_casting(game, enemy);
            break;
        case ENEMY_DEAD:
            lich_boss_dead(game, enemy);
            break;
        default:;
    }
    return 0;
}

int lich_boss_update(game_t *game, enemy_t *enemy)
{
    if (enemy->hp <= 0 && enemy->status != ENEMY_DEAD) {
        enemy->status = ENEMY_DEAD;
        enemy->rect.left = 0;
    }
    lich_boss_animate(game, enemy);
    return 0;
}
