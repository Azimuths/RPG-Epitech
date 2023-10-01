/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** lich_water_spell
*/

#include "projectile.h"
#include "particle.h"
#include "enemy.h"
#include "my.h"
#include "my_linked_list.h"
#include <stdlib.h>

int update_water_skull_spell_projectile(game_t *game, projectile_t *proj)
{
    proj->rot += 5;
    if (proj->color.a < 225)
        proj->color.a += 10;
    proj->scale.x /= 1.05;
    proj->scale.y /= 1.05;
    if (proj->lifetime < 5) {
        proj->dmg = 1;
    }
    sfSprite_setColor(proj->sprite, proj->color);
    return 0;
}

projectile_t *create_water_skull_spell_projectile(void)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);

    proj->sprite = sfSprite_create();
    proj->element = WATER;
    proj->type = WATER_DUCK;
    proj->spd = ((sfVector2f){.x = -2, .y = 5});
    proj->lifetime = 30;
    proj->update = update_water_skull_spell_projectile;
    proj->color = sfWhite;
    proj->color.a = 100;
    proj->hitbox_size = ((sfFloatRect){0, 0, 30, 30});
    proj->scale = ((sfVector2f){5, 5});
    proj->dmg = 0;
    proj->pos = ((sfVector2f){.x = rand() % 1800 + 100, .y = rand() % 1080});
    proj->rot = rand() % 360;
    return proj;
}

int update_water_spell(game_t *game, projectile_t *proj)
{
    add_node(create_water_skull_spell_projectile(), &(game->enemy_proj));
    return 0;
}

projectile_t *create_water_spell(void)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);

    proj->element = WATER;
    proj->type = NO_PARTICLE;
    proj->lifetime = 100;
    proj->update = update_water_spell;
    return proj;
}

int water_lich_spell(game_t *game, enemy_t *enemy)
{
    for (int i = 0; i < 5; ++i) {
        add_node(create_water_spell(), &(game->enemy_proj));
    }
    return 0;
}
