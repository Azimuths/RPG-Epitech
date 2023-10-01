/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_center
*/

#include <SFML/Graphics.h>

int sprite_set_center(sfSprite *sprite)
{
    float width = sfSprite_getLocalBounds(sprite).width / 2.0;
    float height = sfSprite_getLocalBounds(sprite).height / 2.0;
    sfVector2f vector = {width, height};

    sfSprite_setOrigin(sprite, vector);
    return 0;
}

int text_set_center(sfText *text)
{
    float width = sfText_getLocalBounds(text).width / 2.0;
    float height = sfText_getLocalBounds(text).height / 2.0;
    sfVector2f vector = {width, height};

    sfText_setOrigin(text, vector);
    return 0;
}
