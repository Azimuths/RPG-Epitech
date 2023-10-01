/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** lich_ice_spell
*/

#include "projectile.h"
#include "particle.h"
#include "enemy.h"
#include "my.h"
#include "my_linked_list.h"
#include <stdlib.h>

int update_ice_skull_spell_projectile(game_t *game, projectile_t *proj)
{
    const sfVector2f spd[] = {
            ((sfVector2f){.x = -5, .y = 0}),
            ((sfVector2f){.x = -2, .y = 3}),
            ((sfVector2f){.x = 2, .y = 3}),
            ((sfVector2f){.x = 5, .y = 0}),
            ((sfVector2f){.x = 2, .y = -3}),
            ((sfVector2f){.x = -2, .y = -3}),
    };

    if (proj->lifetime == 1 && rand() % 8 == 0) {
        for (int i = 0; i < 6; ++i) {
            add_node(create_ice_skull_spell_projectile(spd[i], proj->pos),
                    &(game->enemy_proj));
        }
    }
    return 0;
}

projectile_t *create_ice_skull_spell_projectile(sfVector2f spd, sfVector2f pos)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);

    proj->sprite = sfSprite_create();
    proj->element = ICE;
    proj->type = ICE_DUCK;
    proj->spd = spd;
    proj->lifetime = 100;
    proj->update = update_ice_skull_spell_projectile;
    proj->color = sfWhite;
    proj->color.a = 100;
    proj->hitbox_size = ((sfFloatRect){0, 0, 30, 30});
    proj->scale = ((sfVector2f){1, 1});
    proj->dmg = 0;
    proj->pos = pos;
    proj->rot = spd.x * 30 + spd.y * 30;
    return proj;
}

int update_ice_spell(game_t *game, projectile_t *proj)
{
    const sfVector2f spd[] = {
            ((sfVector2f){.x = -5, .y = 0}),
            ((sfVector2f){.x = -2, .y = 3}),
            ((sfVector2f){.x = 2, .y = 3}),
            ((sfVector2f){.x = 5, .y = 0}),
            ((sfVector2f){.x = 2, .y = -3}),
            ((sfVector2f){.x = -2, .y = -3}),
    };

    if (proj->lifetime == 0) {
        for (int i = 0; i < 6; ++i) {
            add_node(create_ice_skull_spell_projectile(spd[i], proj->pos),
            &(game->enemy_proj));
        }
    }
    proj->rot += 1;
    return 0;
}

projectile_t *create_ice_spell(void)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);

    proj->sprite = sfSprite_create();
    proj->element = ICE;
    proj->type = ICE_DUCK;
    proj->dmg = 1;
    proj->spd = ((sfVector2f){.x = 0, .y = 10});
    proj->lifetime = 50 + rand() % 30;
    proj->update = update_ice_spell;
    proj->pos = ((sfVector2f){.x = rand() % 1800 + 100, .y = -100});
    proj->scale = ((sfVector2f){2, 2});
    proj->color = sfWhite;
    proj->hitbox_size = ((sfFloatRect){0, 0, 30, 30});
    return proj;
}

int ice_lich_spell(game_t *game, enemy_t *enemy)
{
    for (int i = 0; i < 10; ++i) {
        add_node(create_ice_spell(), &(game->enemy_proj));
    }
    return 0;
}
