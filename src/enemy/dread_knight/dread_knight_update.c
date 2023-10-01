/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** dread_knight_update
*/

#include "enemy.h"

int dread_knight_animate(game_t *game, enemy_t *enemy)
{
    switch (enemy->status) {
        case ENEMY_IDLE:
            dread_knight_idle(game, enemy);
            break;
        case ENEMY_ATTACKING:
            dread_knight_attacking(game, enemy);
            break;
        case ENEMY_MOVING:
            dread_knight_moving(game, enemy);
            break;
        case ENEMY_DEAD:
            dread_knight_dead(game, enemy);
            break;
        default:;
    }
    return 0;
}

int dread_knight_update(game_t *game, enemy_t *enemy)
{
    if (enemy->hp <= 0 && enemy->status != ENEMY_DEAD) {
        enemy->status = ENEMY_DEAD;
        enemy->rect.left = 0;
    }
    face_player(game, enemy);
    if ((enemy->dir == LEFT && enemy->scale.x > 0) ||
            (enemy->dir == RIGHT && enemy->scale.x < 0))
        enemy->scale.x *= -1;
    dread_knight_animate(game, enemy);
    return 0;
}
