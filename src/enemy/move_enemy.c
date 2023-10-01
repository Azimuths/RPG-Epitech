/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** move_enemy
*/

#include "enemy.h"

int move_enemy(enemy_t *enemy, float lenght)
{
    switch (enemy->dir) {
        case UP:
            enemy->pos.y -= lenght + 1;
            break;
        case DOWN:
            enemy->pos.y += lenght + 1;
            break;
        case LEFT:
            enemy->pos.x -= lenght;
            break;
        case RIGHT:
            enemy->pos.x += lenght;
    }
    return 0;
}
