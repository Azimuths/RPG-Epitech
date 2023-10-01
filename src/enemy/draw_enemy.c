/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_enemy
*/

#include "enemy.h"
#include "my_linked_list.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include "particle.h"

int draw_enemy(game_t *game, enemy_t *enemy)
{
    if (enemy->status == ENEMY_TO_DESTROY)
        return 0;
    if (enemy->sprite != NULL) {
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
        sfSprite_setScale(enemy->sprite, enemy->scale);
        sprite_set_center(enemy->sprite);
        sfSprite_setPosition(enemy->sprite, enemy->pos);
        sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
    }
    if (enemy->element_sprite != NULL) {
        sfSprite_setPosition(enemy->element_sprite,
                ((sfVector2f) {.x = enemy->pos.x, .y = enemy->pos.y - 10}));
        sfRenderWindow_drawSprite(game->window, enemy->element_sprite, NULL);
    }
    return 0;
}

int draw_enemies(game_t *game)
{
    enemy_t *buf = 0;
    linked_list_t *list = game->enemies;

    while (list != NULL) {
        buf = ((enemy_t *)(list->data));
        list = list->next;
        draw_enemy(game, buf);
    }
    return 0;
}
