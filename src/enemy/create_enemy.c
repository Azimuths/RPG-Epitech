/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_necro
*/

#include "enemy.h"
#include "my.h"
#include "stdlib.h"
#include "particle.h"

int init_enemy_element_and_hp(game_t *game, enemy_t *dest)
{
    dest->element = rand() % 4;
    dest->element_sprite = sfSprite_create();
    sfSprite_setTexture(dest->element_sprite,
            game->textures->particles[dest->element], sfFalse);
    sfSprite_setOrigin(dest->element_sprite,
            ((sfVector2f){.x = 7.5, .y = 7.5}));
    sfSprite_setScale(dest->element_sprite,
            ((sfVector2f){.x = dest->scale.x / 2, .y = dest->scale.x / 2}));
    if (dest->type == DEATH_KNIGHT) {
        dest->hp = 24;
        dest->atk = 24;
    } else if (dest->type == DREAD_KNIGHT) {
        dest->hp = 60;
        dest->atk = 12;
    } else {
        dest->hp = 24;
        dest->atk = 48;
    }
    return 0;
}

enemy_t *create_enemy(game_t *game, enemy_type_t type, sfVector2f pos)
{
    enemy_t *dest = my_memset(sizeof(enemy_t), NULL);

    dest->sprite = sfSprite_create();
    dest->texture = game->textures->enemies[type];
    sfSprite_setTexture(dest->sprite, dest->texture, sfFalse);
    dest->type = type;
    dest->status = ENEMY_IDLE;
    dest->hp = 12;
    dest->atk = 12;
    dest->rect = ((sfIntRect){.top = 0, .left = 0, .width = 32, .height = 32});
    dest->scale = ((sfVector2f){.x = 3, .y = 3});
    dest->clock = sfClock_create();
    dest->pos = ((sfVector2f){.x = pos.x, .y = pos.y});
    dest->exp = 100;
    dest->hitbox_size = ((sfFloatRect){15, 4, 40, 50});
    dest->dir = RIGHT;
    sprite_set_center(dest->sprite);
    sfSprite_setPosition(dest->sprite, dest->pos);
    init_enemy_element_and_hp(game, dest);
    return dest;
}

int destroy_enemy_contents(enemy_t *enemy)
{
    sfSprite_destroy(enemy->sprite);
    sfSprite_destroy(enemy->element_sprite);
    sfClock_destroy(enemy->clock);
    return 0;
}

void check_boss_end(game_t *game, enemy_t *enemy)
{
    if (enemy->type == LICH) {
        game->screen = END_SCREEN;
    }
}

int destroy_enemy_and_update_xp(game_t *game, enemy_t *enemy)
{
    check_boss_end(game, enemy);
    sfSprite_destroy(enemy->sprite);
    sfSprite_destroy(enemy->element_sprite);
    sfClock_destroy(enemy->clock);
    game->player->exp += enemy->exp;
    while (game->player->exp > 100) {
        game->player->exp -= 100;
        game->player->level++;
        game->skill_points++;
        game->player->dmg++;
        add_node(create_xp_particle(game), &(game->particles));
        for (int i = 0; i < 25; ++i) {
            add_node(create_star_particle_on_player(game), &(game->particles));
        }
    }
    add_node(create_xp_particle(game), &(game->particles));
    return 0;
}
