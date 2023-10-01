/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** particle
*/

#include "particle.h"
#include "my_linked_list.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

int draw_particle(game_t *game, particle_t *part)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f origin = {
            sfTexture_getSize(game->textures->particles[part->type]).x / 2,
            sfTexture_getSize(game->textures->particles[part->type]).y / 2};

    sfSprite_setScale(sprite, part->scale);
    sfSprite_setOrigin(sprite, origin);
    sfSprite_setTexture(sprite, game->textures->particles[part->type], sfTrue);
    sfSprite_setPosition(sprite, part->pos);
    sfSprite_setColor(sprite, part->color);
    sfSprite_setRotation(sprite, part->rot);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfSprite_destroy(sprite);
    return 0;
}

int draw_particles(game_t *game)
{
    particle_t *buf = 0;
    linked_list_t *list = game->particles;

    while (list != NULL) {
        buf = ((particle_t *)(list->data));
        list = list->next;
        draw_particle(game, buf);
    }
    return 0;
}
