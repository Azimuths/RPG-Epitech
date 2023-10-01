/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** deal_damage
*/

#include "projectile.h"

float get_multiplier(element_t attack, element_t def)
{
    float multiplyer = 1;

    if (attack == FIRE && def == ICE ||
        attack == ICE && def == WATER ||
        attack == WATER && def == ROCK ||
        attack == ROCK && def == FIRE)
        multiplyer *= 2;
    if (attack == ICE && def == FIRE ||
        attack == WATER && def == ICE ||
        attack == ROCK && def == WATER ||
        attack == ROCK && def == FIRE)
        multiplyer /= 2;
    return multiplyer;
}
