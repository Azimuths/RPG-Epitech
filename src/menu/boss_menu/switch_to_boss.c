/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** switch_to_boss
*/

#include "rpg.h"
#include "inventory.h"
#include "sounds.h"
#include "macro.h"

void switch_to_boss(game_t *game)
{
    int count = 0;

    for (int i = 0; i < NB_INVENTORY_SLOTS; ++i) {
        if (game->inventory->contents[i] == WEAPON_FIRE_DUCK)
            count++;
        if (game->inventory->contents[i] == WEAPON_WATER_DUCK)
            count++;
        if (game->inventory->contents[i] == WEAPON_ICE_DUCK)
            count++;
        if (game->inventory->contents[i] == WEAPON_ROCK_DUCK)
            count++;
    }
    if (count == 4) {
        change_music(game, BOSS_MUSIC);
        clear_screen(game);
        game->screen = BOSS_MENU;
    }
}
