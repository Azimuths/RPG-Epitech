/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_date
*/

#include "rpg.h"
#include "particle.h"
#include <stdlib.h>

int update_weather(game_t *game)
{
    particle_t *(*create_particle[])(void) = {NULL,
            create_rain_particle,
            create_snow_particle};

    if (game->weather == CLEAR)
        return 0;
    for (int i = 0; i < 2; ++i)
        add_node(create_particle[game->weather](), &(game->particles));
    return 0;
}

int update_date(game_t *game)
{
    game->time += 2;
    if (sfKeyboard_isKeyPressed(sfKeyW))
        game->time = (game->time % 60) * 60;
    if (sfKeyboard_isKeyPressed(sfKeyT))
        game->time += 360;
    if (game->time >= 1440)
        game->time -= 1440;
    if (game->time % 60 == 0)
        game->weather = rand() % NB_WEATHER;
    game->daytime = game->time / 360;
    return 0;
}
