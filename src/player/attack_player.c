/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** attack_player
*/

#include "player.h"
#include "inventory.h"
#include "projectile.h"

int attack_player(game_t *game)
{
    weapon_t weapon = game->inventory->contents[game->inventory->curr];

    if (weapon == WEAPON_SWORD)
        sword_shoot(game, game->player);
    if (weapon == WEAPON_FIRE_DUCK)
        add_node(create_fire_duck_projectile(game->player), &
        (game->projectiles));
    if (weapon == WEAPON_ICE_DUCK) {
        add_node(create_ice_duck_projectile(game->player),
                &(game->projectiles));
        add_node(create_other_ice_duck_projectile(game->player), &
        (game->projectiles));
    }
    if (weapon == WEAPON_ROCK_DUCK)
        add_node(create_rock_duck_projectile(game->player), &
        (game->projectiles));
    if (weapon == WEAPON_WATER_DUCK)
        add_node(create_rock_duck_projectile(game->player), &
        (game->projectiles));
    return 0;
}
