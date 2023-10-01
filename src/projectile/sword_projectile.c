/*
** EPITECH PROJECT, 2022
** sword
** File description:
** sword_projectile
*/

#include "enemy.h"
#include "projectile.h"
#include "my.h"

projectile_t *create_sword_projectile(player_t *player)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->pos = player->pos;
    dest->lifetime = 20;
    dest->type = NO_PARTICLE;
    dest->hitbox_size = ((sfFloatRect){20, 20, 50, 50});
    if (player->dir == LEFT)
        dest->hitbox_size.top *= -1;
    if (player->dir == DOWN)
        dest->hitbox_size.top *= -1;
    dest->update = NULL;
    dest->dmg = 10 + player->dmg;
    dest->element = NO_ELEMENT;
    return dest;
}

int sword_shoot(game_t *game, player_t *player)
{
    add_node(create_sword_projectile(player), &(game->projectiles));
    return 0;
}
