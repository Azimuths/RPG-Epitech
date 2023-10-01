/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** view clear on scroll
*/

#include "rpg.h"
#include "projectile.h"
#include "particle.h"
#include "enemy.h"
#include "collectable.h"

void clear_screen(game_t *game)
{
    destroy_enemies(game);
    destroy_projectiles(game, &game->projectiles);
    destroy_projectiles(game, &game->enemy_proj);
    destroy_particles(game);
    destroy_collectables(game);
}
