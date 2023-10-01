/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** lich_boss_update
*/

#include "enemy.h"
#include "stdlib.h"

int lich_boss_dead(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.1))
        return 0;
    enemy->rect.left += 32;
    if (enemy->rect.top != 192)
        enemy->rect.top = 192;
    if (enemy->rect.left > 128) {
        enemy->status = ENEMY_TO_DESTROY;
    }
    return 0;
}

int lich_boss_attacking(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.2))
        return 0;
    if (enemy->rect.top != 64)
        enemy->rect.top = 64;
    enemy->rect.left += 32;
    if (enemy->rect.left > 192) {
        enemy->status = ENEMY_IDLE;
        enemy->rect.left = 0;
        return 0;
    }
    return 0;
}

int lich_boss_idle(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.2))
        return 0;
    if (enemy->rect.top != 0)
        enemy->rect.top = 0;
    enemy->rect.left += 32;
    if (enemy->rect.left > 96) {
        enemy->rect.left = 0;
        if (rand() % 5 != 0)
            return 0;
        if (get_player_distance(game, enemy->pos) < 250) {
            enemy->status = ENEMY_ATTACKING;
            return 0;
        }
        if (get_player_distance(game, enemy->pos) > 250 && (rand() % 5) != 0)
            enemy->status = ENEMY_CASTING;
        else
            enemy->status = ENEMY_SUMMON;
    }
    return 0;
}

int lich_boss_summoning(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.2))
        return 0;
    if (enemy->rect.top != 128)
        enemy->rect.top = 128;
    enemy->rect.left += 32;
    if (enemy->rect.left > 160) {
        enemy->status = ENEMY_IDLE;
        enemy->rect.left = 0;
        return 0;
    }
    if (enemy->rect.left == 96)
        lich_boss_summon(game);
    return 0;
}

void lich_boss_casting(game_t *game, enemy_t *enemy)
{
    if (!get_time(enemy->clock, 0.2))
        return;
    if (enemy->rect.top != 96)
        enemy->rect.top = 96;
    enemy->rect.left += 32;
    if (enemy->rect.left == 128) {
        if (enemy->element == ICE)
            ice_lich_spell(game, enemy);
        if (enemy->element == FIRE)
            fire_lich_spell(game, enemy);
        if (enemy->element == ROCK)
            rock_lich_spell(game, enemy);
        if (enemy->element == WATER)
            water_lich_spell(game, enemy);
    }
    if (enemy->rect.left > 224) {
        enemy->status = ENEMY_IDLE;
        enemy->rect.left = 0;
        change_enemy_element(game, enemy);
    }
}
