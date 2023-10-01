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

int update_fire_skull_spell_projectile(game_t *game, projectile_t *proj)
{
    proj->rot += 5;
    return 0;
}

projectile_t *create_fire_skull_spell_projectile(game_t *game, sfVector2f spd)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);
    int offset = 0;

    proj->sprite = sfSprite_create();
    proj->element = FIRE;
    proj->type = FIRE_DUCK;
    proj->spd = spd;
    proj->lifetime = 100;
    proj->update = update_fire_skull_spell_projectile;
    proj->color = sfWhite;
    proj->color.a = 100;
    proj->hitbox_size = ((sfFloatRect){0, 0, 30, 30});
    proj->scale = ((sfVector2f){2, 2});
    proj->dmg = 0;
    proj->pos = ((sfVector2f){.x = 1920, .y = 540});
    proj->rot = rand() % 360;
    return proj;
}

int update_fire_spell(game_t *game, projectile_t *proj)
{
    sfVector2f spd = ((sfVector2f){-30, -15});

    if (proj->lifetime != 100 && proj->lifetime != 50)
        return 0;
    for (int i = 0; i < 5; ++i) {
        spd.y += 5;
        spd.x = -30 + (fabsolute(spd.y) / 2);
        for (int j = 0; j < 6; ++j)
            add_node(create_fire_skull_spell_projectile(game, spd),
                    &(game->enemy_proj));
    }
    fire_spell_second_spell(game, proj);
    return 0;
}

projectile_t *create_fire_spell(void)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);

    proj->element = FIRE;
    proj->type = NO_PARTICLE;
    proj->lifetime = 101;
    proj->update = update_fire_spell;
    return proj;
}

int fire_lich_spell(game_t *game, enemy_t *enemy)
{
    add_node(create_fire_spell(), &(game->enemy_proj));
    return 0;
}
