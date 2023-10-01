/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_time
*/

#include "SFML/System.h"

int get_time(sfClock *clock, double seconds)
{
    sfInt64 microseconds = ((sfInt64)(seconds * 1000000));

    if (sfClock_getElapsedTime(clock).microseconds > microseconds) {
        sfClock_restart(clock);
        return sfTrue;
    }
    return sfFalse;
}
