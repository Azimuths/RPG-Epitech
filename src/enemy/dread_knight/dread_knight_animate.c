/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** dread_knight_animate
*/

#include "rpg.h"
#include "enemy.h"
#include <stdlib.h>

int dread_knight_dead(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.1))
        return 0;
    if (enemy->rect.top != 192)
        enemy->rect.top = 192;
    enemy->rect.left += 32;
    if (enemy->rect.left > 128) {
        enemy->status = ENEMY_TO_DESTROY;
    }
}

int dread_knight_moving(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.2))
        return 0;
    if (enemy->rect.top != 32)
        enemy->rect.top = 32;
    enemy->rect.left += 32;
    if (enemy->rect.left > 160) {
        enemy->rect.left = 0;
        if (rand() % 10 < 3)
            enemy->status = ENEMY_IDLE;
        if (get_player_distance(game, enemy->pos) < 150.0)
            enemy->status = ENEMY_ATTACKING;
    }
    move_enemy(enemy, 2);
    return 0;
}

int dread_knight_attacking(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.2))
        return 0;
    if (enemy->rect.top != 96)
        enemy->rect.top = 96;
    enemy->rect.left += 32;
    if (enemy->rect.left > 128) {
        if (rand() % 10 < 3)
            enemy->dir = rand() % 4;
        enemy->status = ENEMY_MOVING;
        if (get_player_distance(game, enemy->pos) > 500.0)
            enemy->status = ENEMY_IDLE;
        enemy->rect.left = 0;
        return 0;
    }
    if (enemy->rect.left == 64)
        dread_knight_shoot(game, enemy);
    return 0;
}

int dread_knight_idle(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.2))
        return 0;
    if (get_player_distance(game, enemy->pos) < 150.0) {
        enemy->rect.left = 0;
        enemy->status = ENEMY_ATTACKING;
        return 0;
    }
    if (rand() % 5 == 0) {
        enemy->dir = rand() % 4;
        enemy->status = ENEMY_MOVING;
        return 0;
    }
    if (enemy->rect.top != 0)
        enemy->rect.top = 0;
    enemy->rect.left += 32;
    if (enemy->rect.left > 96)
        enemy->rect.left = 0;
}
