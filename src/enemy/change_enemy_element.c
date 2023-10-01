/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** change_enemy_element
*/

#include "enemy.h"

int change_enemy_element(game_t *game, enemy_t *enemy)
{
    enemy->element += 1;
    if (enemy->element == NB_ELEMENT)
        enemy->element = 0;
    sfSprite_setTexture(enemy->element_sprite,
            game->textures->particles[enemy->element], sfTrue);
    return 0;
}
