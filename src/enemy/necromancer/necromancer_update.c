/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** necro_update
*/

#include "enemy.h"

int necromancer_animate(game_t *game, enemy_t *enemy)
{
    switch (enemy->status) {
        case ENEMY_IDLE:
            necromancer_idle(game, enemy);
            break;
        case ENEMY_ATTACKING:
            necromancer_attacking(game, enemy);
            break;
        case ENEMY_MOVING:
            necromancer_moving(game, enemy);
            break;
        case ENEMY_DEAD:
            necromancer_dead(game, enemy);
            break;
        default:;
    }
    return 0;
}

int necromancer_update(game_t *game, enemy_t *enemy)
{
    if (enemy->hp <= 0 && enemy->status != ENEMY_DEAD) {
        enemy->status = ENEMY_DEAD;
        enemy->rect.left = 0;
    }
    face_player(game, enemy);
    if ((enemy->dir == LEFT && enemy->scale.x > 0) ||
            (enemy->dir == RIGHT && enemy->scale.x < 0))
        enemy->scale.x *= -1;
    necromancer_animate(game, enemy);
    return 0;
}
