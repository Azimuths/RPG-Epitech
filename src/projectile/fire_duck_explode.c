/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fire_duck_explode
*/

#include "rpg.h"
#include "projectile.h"
#include "my.h"

int update_explosion_proj(game_t *game, projectile_t *proj)
{
    return 0;
}

projectile_t *create_explosion_proj(sfVector2f spd, sfVector2f pos)
{
    projectile_t *proj = my_memset(sizeof(projectile_t), NULL);

    proj->sprite = sfSprite_create();
    proj->element = FIRE;
    proj->type = FIRE_DUCK;
    proj->spd = spd;
    proj->lifetime = 10;
    proj->update = update_explosion_proj;
    proj->color = sfWhite;
    proj->color.a = 100;
    proj->hitbox_size = ((sfFloatRect){0, 0, 3, 3});
    proj->scale = ((sfVector2f){0.5, 0.5});
    proj->dmg = 1;
    proj->pos.x = pos.x + spd.x * 2;
    proj->pos.y = pos.y + spd.y * 2;
    proj->rot = spd.x * 30 + spd.y * 30;
    return proj;
}

int fire_duck_explode(game_t *game, projectile_t *proj)
{
    const sfVector2f spd[] = {
            ((sfVector2f){.x = -4, .y = 0}),
            ((sfVector2f){.x = -3, .y = 2}),
            ((sfVector2f){.x = -2, .y = 3}),
            ((sfVector2f){.x = 0, .y = 4}),
            ((sfVector2f){.x = 2, .y = 3}),
            ((sfVector2f){.x = 3, .y = 2}),
            ((sfVector2f){.x = 4, .y = 0}),
            ((sfVector2f){.x = 3, .y = -2}),
            ((sfVector2f){.x = 2, .y = -3}),
            ((sfVector2f){.x = 0, .y = -4}),
            ((sfVector2f){.x = -3, .y = -3}),
    };

    for (int i = 0; i < 11; ++i) {
        add_node(create_explosion_proj(spd[i], proj->pos),
                &(game->projectiles));
    }
    return 0;
}
