/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** check_colision
*/

#include "projectile.h"
#include "enemy.h"

int check_collision_enemy(projectile_t *proj, enemy_t *enemy, game_t *game)
{
    sfFloatRect en = {0};
    sfFloatRect proj_rect = {0};

    if (enemy->status == ENEMY_DEAD || enemy->status == ENEMY_TO_DESTROY)
        return 0;
    en = get_hitbox(enemy->pos, enemy->hitbox_size);
    proj_rect = get_hitbox(proj->pos, proj->hitbox_size);
    if (sfFloatRect_intersects(&en, &proj_rect, NULL) == sfTrue) {
        enemy->hp -= proj->dmg * get_multiplier(proj->element, enemy->element);
        proj->lifetime = 0;
    }
    return 0;
}

int check_collisions_projectile(game_t *game)
{
    linked_list_t *proj = NULL;
    linked_list_t *enemy = game->enemies;

    while (enemy != NULL) {
        proj = game->projectiles;
        while (proj != NULL) {
            check_collision_enemy(proj->data, enemy->data, game);
            proj = proj->next;
        }
        enemy = enemy->next;
    }
}

int check_collision_player(projectile_t *proj, player_t *player, game_t *game)
{
    sfFloatRect en = {0};
    sfFloatRect proj_rect = {0};

    en = get_hitbox(player->pos, player->hitbox_size);
    proj_rect = get_hitbox(proj->pos, proj->hitbox_size);
    if (sfFloatRect_intersects(&en, &proj_rect, NULL) == sfTrue)
        player->hp -= proj->dmg;
    return 0;
}

int check_collisions_enemy_projectile(game_t *game)
{
    linked_list_t *proj = game->enemy_proj;

    while (proj != NULL) {
        check_collision_player(proj->data, game->player, game);
        proj = proj->next;
    }
}
