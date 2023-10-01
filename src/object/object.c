/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** object
*/

#include "rpg.h"
#include <stdlib.h>

object_t *create_object(char *filepath, sfIntRect rect, sfVector2f position,
sfVector2f scale)
{
    object_t *object = (object_t *)malloc(sizeof(object_t));

    object->texture_path = filepath;
    object->rect = rect;
    if (!(object->texture = sfTexture_createFromFile(filepath, NULL)))
        return NULL;
    if (!(object->sprite = sfSprite_create()))
        return NULL;
    object->pos = position;
    object->scale = scale;
    sfSprite_setPosition(object->sprite, object->pos);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, object->scale);
    sfSprite_setTextureRect(object->sprite, object->rect);
    return object;
}

void draw_object(object_t *obj, game_t *game)
{
    sfRenderWindow_drawSprite(game->window, obj->sprite, NULL);
}

void delete_object(object_t *object)
{
    if (object->sprite)
        sfSprite_destroy(object->sprite);
    if (object->texture)
        sfTexture_destroy(object->texture);
    free(object);
}
