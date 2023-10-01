/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_enemy
*/

#include "enemy.h"
#include "my_linked_list.h"

int update_enemies(game_t *game)
{
    enemy_t *buf = 0;
    linked_list_t *list = NULL;
    int (*update[])(game_t *game, enemy_t *enemy) = {
            death_knight_update, dread_knight_update, necromancer_update,
            lich_boss_update, NULL, pnj_quest_update};

    clear_enemies(game);
    list = game->enemies;
    while (list != NULL) {
        buf = ((enemy_t *)(list->data));
        list = list->next;
        buf->pos.y += buf->spd.y;
        buf->pos.x += buf->spd.x;
        update[buf->type](game, buf);
    }
    return 0;
}

int clear_enemies(game_t *game)
{
    linked_list_t *prev = NULL;
    linked_list_t *list = NULL;

    while (game->enemies != NULL &&
            ((enemy_t *)(game->enemies->data))->status == ENEMY_TO_DESTROY) {
        destroy_enemy_and_update_xp(game, game->enemies->data);
        del_first_node(&(game->enemies));
    }
    list = game->enemies;
    while (list != NULL) {
        if (((enemy_t *)(list->data))->status == ENEMY_TO_DESTROY) {
            destroy_enemy_and_update_xp(game, list->data);
            delete_node(&prev);
            list = prev;
        }
        prev = list;
        list = list->next;
    }
    return 0;
}

int destroy_enemies(game_t *game)
{
    while (game->enemies != NULL) {
        destroy_enemy_contents(game->enemies->data);
        del_first_node(&(game->enemies));
    }
    return 0;
}
