/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_projectile
*/

#include "projectile.h"
#include "my_linked_list.h"
#include "rpg.h"
#include <SFML/Graphics.h>

int draw_projectile(game_t *game, projectile_t *proj)
{
    sfVector2f origin = {0};

    if (proj->type == NO_PARTICLE)
        return 0;
    origin = ((sfVector2f){
        sfTexture_getSize(game->textures->projectile[proj->type]).x / 2,
        sfTexture_getSize(game->textures->projectile[proj->type]).y / 2});
    sfSprite_setScale(proj->sprite, proj->scale);
    sfSprite_setOrigin(proj->sprite, origin);
    sfSprite_setTexture(proj->sprite, game->textures->projectile[proj->type],
            sfTrue);
    sfSprite_setPosition(proj->sprite, proj->pos);
    sfSprite_setColor(proj->sprite, proj->color);
    sfSprite_setRotation(proj->sprite, proj->rot);
    sprite_set_center(proj->sprite);
    sfRenderWindow_drawSprite(game->window, proj->sprite, NULL);
    return 0;
}

int draw_projectiles(game_t *game, linked_list_t **list_proj)
{
    projectile_t *buf = 0;
    linked_list_t *list = *list_proj;

    while (list != NULL) {
        buf = ((projectile_t *)(list->data));
        list = list->next;
        draw_projectile(game, buf);
    }
    return 0;
}

int destroy_projectile(projectile_t *projectile)
{
    sfSprite_destroy(projectile->sprite);
    return 0;
}
