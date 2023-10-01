/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** put_filter
*/

#include "rpg.h"
#include "particle.h"
#include <stdlib.h>

int put_filter(game_t *game)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {1920, 1080};
    sfColor colors[] = {MORNINGCOLOR, AFTERNOONCOLOR, EVENINGCOLOR,
            NIGHTCOLOR};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, colors[game->daytime]);
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
    return 0;
}
