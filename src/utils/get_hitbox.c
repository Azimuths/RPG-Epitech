/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_hitbox
*/

#include "SFML/Graphics.h"
#include "particle.h"
#include <stdlib.h>

sfFloatRect get_hitbox(sfVector2f center, sfFloatRect hitbox)
{
    sfFloatRect rect = {0};

    rect.top = center.x - (hitbox.height / 2) + hitbox.top;
    rect.left = center.y - (hitbox.width / 2) + hitbox.left;
    rect.width = hitbox.width;
    rect.height = hitbox.height;
    return rect;
}

sfFloatRect show_hitbox(sfVector2f pt, sfFloatRect box, sfRenderWindow *win)
{
    sfFloatRect rect = {0};
    sfRectangleShape *shape = sfRectangleShape_create();

    rect.top = pt.x - (box.height / 2) + box.top;
    rect.left = pt.y - (box.width / 2) + box.left;
    rect.width = box.width;
    rect.height = box.height;
    sfRectangleShape_setSize(shape, ((sfVector2f){.x = rect.width,
            .y = rect.height}));
    sfRectangleShape_setPosition(shape, ((sfVector2f){.x = rect.top,
            .y = rect.left}));
    sfRectangleShape_setFillColor(shape, ((sfColor){255, 0, 0, 50}));
    sfRenderWindow_drawRectangleShape(win, shape, NULL);
    sfRectangleShape_destroy(shape);
    return rect;
}
