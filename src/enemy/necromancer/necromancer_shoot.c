/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** necromancer_shoot
*/

#include "enemy.h"
#include "particle.h"
#include "projectile.h"
#include <stdlib.h>
#include "my.h"
#include "rpg.h"

int update_shotgun_particle(game_t *game, projectile_t *particle)
{
    particle->spd.y = (float)(particle->spd.y / 1.05);
    particle->spd.x = (float)(particle->spd.x / 1.05);
    particle->rot += rand() % 50;
    return 0;
}

projectile_t *create_shotgun_particle(enemy_t *enemy)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->sprite = sfSprite_create();
    dest->pos.x = enemy->pos.x - enemy->spd.x + (rand() % 40 - 20);
    dest->pos.y = enemy->pos.y - enemy->spd.y + (rand() % 40 - 20);
    dest->color = sfWhite;
    dest->lifetime = 50;
    dest->type = (projectile_type_t)enemy->element;
    dest->spd.y = (rand() % 10) - 5;
    dest->spd.x = 5;
    if (enemy->scale.x < 0)
        dest->spd.x *= -1;
    dest->update = update_shotgun_particle;
    dest->scale = ((sfVector2f){.x = 0.5, .y = 0.5});
    dest->hitbox_size = ((sfFloatRect){0, 0, 20, 20});
    dest->dmg = 1;
    return dest;
}

int necromancer_shoot(game_t *game, enemy_t *enemy)
{
    for (int i = 0; i < 20; ++i)
        add_node(create_shotgun_particle(enemy), &(game->enemy_proj));
    return 0;
}
