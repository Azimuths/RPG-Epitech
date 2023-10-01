/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** spawn ennemies
*/

#include "rpg.h"
#include "projectile.h"
#include "particle.h"
#include "enemy.h"
#include "collectable.h"
#include "inventory.h"

static void test_enemy(game_t *game, int x, int y)
{
    if (game->map->collision_map[
    get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == 'N') {
        add_node(create_enemy(
            game, NECROMANCER, (sfVector2f){x * 96, y * 96}
        ), &(game->enemies));
    }
    if (game->map->collision_map[
    get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == 'X') {
        add_node(create_enemy(
            game, DEATH_KNIGHT, (sfVector2f){x * 96, y * 96}
        ), &(game->enemies));
    }
    if (game->map->collision_map[
    get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == 'Z') {
        add_node(create_enemy(
            game, DREAD_KNIGHT, (sfVector2f){x * 96, y * 96}
        ), &(game->enemies));
    }
}

static void test_duck_second(game_t *game, int x, int y)
{
    int water = 0;
    int rock = 0;

    for (int i = 0; i < NB_INVENTORY_SLOTS; ++i) {
        if (game->inventory->contents[i] == WEAPON_ROCK_DUCK)
            rock = 1;
        if (game->inventory->contents[i] == WEAPON_WATER_DUCK)
            water = 1;
    }
    if (game->map->collision_map[
    get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == 'V' && water != 1) {
        add_node(create_water_duck_collectable(
            game, ((sfVector2f){x * 96, y * 96})), &(game->collectables));
    }
    if (game->map->collision_map[
    get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == 'D' && rock != 1) {
        add_node(create_rock_duck_collectable(
            game, ((sfVector2f){x * 96, y * 96})), &(game->collectables));
    }
}

static void test_duck(game_t *game, int x, int y)
{
    int fire = 0;
    int ice = 0;

    for (int i = 0; i < NB_INVENTORY_SLOTS; ++i) {
        if (game->inventory->contents[i] == WEAPON_FIRE_DUCK)
            fire = 1;
        if (game->inventory->contents[i] == WEAPON_ICE_DUCK)
            ice = 1;
    }
    if (game->map->collision_map[
    get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == 'T' && fire != 1) {
        add_node(create_fire_duck_collectable(
            game, ((sfVector2f){x * 96, y * 96})), &(game->collectables));
    }
    if (game->map->collision_map[
    get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == 'I' && ice != 1) {
        add_node(create_ice_duck_collectable(
            game, ((sfVector2f){x * 96 + 48, y * 96 + 48})),
                    &(game->collectables));
    }
}

static void test_pnj(game_t *game, int x, int y)
{
    if (game->map->collision_map[
    get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == 'P') {
        add_node(create_pnj_quest(
            game, ((sfVector2f){x * 96, y * 96})), &(game->enemies));
    }
}

void spawn_entity(game_t *game)
{
    for (int x = 0; x < 20; ++x) {
        for (int y = 0; y < 11; ++y) {
            test_enemy(game, x, y);
            test_duck(game, x, y);
            test_duck_second(game, x, y);
            test_pnj(game, x, y);
        }
    }
}
