/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** death_knight_shoot
*/

#include "enemy.h"
#include "projectile.h"
#include "my.h"

projectile_t *create_deathknight_sword(enemy_t *enemy)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->pos.x = enemy->pos.x;
    dest->pos.y = enemy->pos.y;
    dest->lifetime = 10;
    dest->type = NO_PARTICLE;
    dest->hitbox_size = ((sfFloatRect){20, 20, 50, 50});
    if (enemy->scale.x < 0)
        dest->hitbox_size.top *= -1;
    dest->update = NULL;
    dest->dmg = 1;
    dest->element = enemy->element;
    return dest;
}

int death_knight_shoot(game_t *game, enemy_t *enemy)
{
    add_node(create_deathknight_sword(enemy), &(game->enemy_proj));
    return 0;
}
