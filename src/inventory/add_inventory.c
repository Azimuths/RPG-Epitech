/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** add_inventory
*/

#include "inventory.h"
#include "rpg.h"

int add_inventory(game_t *game, weapon_t weapon)
{
    inventory_t *inv = game->inventory;
    int i = 0;

    while (inv->contents[i] != WEAPON_NONE && i < NB_INVENTORY_SLOTS) {
        i++;
    }
    if (i != NB_INVENTORY_SLOTS) {
        game->inventory->contents[i] = weapon;
    }
    return 0;
}
