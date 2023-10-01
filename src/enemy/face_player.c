/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** face_player
*/

#include "enemy.h"

void face_player(game_t *game, enemy_t *enemy)
{
    dir_t dest = 0;
    if (get_player_distance(game, enemy->pos) > 150.0)
        return;
    if (enemy->scale.x > 0 && get_player_vector(game, enemy->pos).x < 0) {
        if (enemy->dir == RIGHT)
            enemy->dir = LEFT;
        else
            enemy->scale.x *= -1;
        return;
    }
    if (enemy->scale.x < 0  && get_player_vector(game, enemy->pos).x > 0) {
        if (enemy->dir == LEFT)
            enemy->dir = RIGHT;
        else
            enemy->scale.x *= -1;
    }
    return;
}
