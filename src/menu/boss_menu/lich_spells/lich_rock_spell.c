/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** lich_fire_spell
*/

#include "projectile.h"
#include "particle.h"
#include "enemy.h"
#include "my.h"
#include "my_linked_list.h"
#include <stdlib.h>

int update_rock_skull_spell_projectile(game_t *game, projectile_t *proj)
{
    proj->rot += 10;
    if (proj->color.a < 225)
        proj->color.a += 10;
    proj->scale.x *= 1.02;
    proj->scale.y *= 1.02;
    proj->hitbox_size.width *= 1.02;
    proj->hitbox_size.height *= 1.02;
    proj->dmg *= 1.05;
    sfSprite_setColor(proj->sprite, proj->color);
    return 0;
}

projectile_t *create_rock_skull_spell_projectile(void)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);

    proj->sprite = sfSprite_create();
    proj->element = ROCK;
    proj->type = ROCK_DUCK;
    proj->spd = ((sfVector2f){.x = 0, .y = 10});
    proj->lifetime = 100;
    proj->update = update_rock_skull_spell_projectile;
    proj->color = sfWhite;
    proj->color.a = 100;
    proj->hitbox_size = ((sfFloatRect){0, 0, 30, 30});
    proj->scale = ((sfVector2f){1, 1});
    proj->dmg = 0;
    proj->pos = ((sfVector2f){.x = rand() % 1800 + 100, .y = 0});
    proj->rot = rand() % 360;
    return proj;
}

int update_rock_spell(game_t *game, projectile_t *proj)
{
    add_node(create_rock_skull_spell_projectile(), &(game->enemy_proj));
    return 0;
}

projectile_t *create_rock_spell(void)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);

    proj->element = ROCK;
    proj->type = NO_PARTICLE;
    proj->lifetime = 100;
    proj->update = update_rock_spell;
    return proj;
}

int rock_lich_spell(game_t *game, enemy_t *enemy)
{
    add_node(create_rock_spell(), &(game->enemy_proj));
    return 0;
}
