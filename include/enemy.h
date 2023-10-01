/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemy
*/

#include "rpg.h"
#include "player.h"
#include "SFML/Graphics.h"

#ifndef ENEMY_H
    #define ENEMY_H

typedef enum enemy_status_e {
    ENEMY_IDLE,
    ENEMY_MOVING,
    ENEMY_ATTACKING,
    ENEMY_CASTING,
    ENEMY_SUMMON,
    ENEMy_GETHIT,
    ENEMY_DEAD,
    ENEMY_TO_DESTROY
} enemy_status_t;

typedef enum enemy_type_e {
    DEATH_KNIGHT,
    DREAD_KNIGHT,
    NECROMANCER,
    LICH,
    NB_ENEMY_TYPES,
    PNJ_QUEST
} enemy_type_t;

typedef struct enemy_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f spd;
    int hp;
    int atk;
    int exp;
    enemy_type_t type;
    enemy_status_t status;
    element_t element;
    sfSprite *element_sprite;
    dir_t dir;
    sfFloatRect hitbox_size;
} enemy_t;

    #define NECRO_TEXT "assets/enemy/necro.png"
    #define DEATH_KNIGHT_TEXT "assets/enemy/death_knight.png"
    #define DREAD_KNIGHT_TEXT "assets/enemy/dread_knight.png"
    #define LICH_TEXT "assets/enemy/lich.png"

int update_enemies(game_t *game);
int draw_enemies(game_t *game);
enemy_t *create_enemy(game_t *game, enemy_type_t type, sfVector2f pos);
int death_knight_update(game_t *game, enemy_t *enemy);
int dread_knight_update(game_t *game, enemy_t *enemy);
int necromancer_update(game_t *game, enemy_t *enemy);
int clear_enemies(game_t *game);
int necromancer_shoot(game_t *game, enemy_t *enemy);
int dread_knight_dead(game_t *game, enemy_t *enemy);
int dread_knight_moving(game_t *game, enemy_t *enemy);
int dread_knight_attacking(game_t *game, enemy_t *enemy);
int dread_knight_idle(game_t *game, enemy_t *enemy);
int dread_knight_shoot(game_t *game, enemy_t *enemy);
float get_multiplier(element_t attack, element_t def);
int death_knight_shoot(game_t *game, enemy_t *enemy);
int death_knight_idle(game_t *game, enemy_t *enemy);
int death_knight_attacking(game_t *game, enemy_t *enemy);
int death_knight_moving(game_t *game, enemy_t *enemy);
int death_knight_attacking(game_t *game, enemy_t *enemy);
int death_knight_dead(game_t *game, enemy_t *enemy);
int necromancer_idle(game_t *game, enemy_t *enemy);
int necromancer_attacking(game_t *game, enemy_t *enemy);
int necromancer_moving(game_t *game, enemy_t *enemy);
int necromancer_attacking(game_t *game, enemy_t *enemy);
int necromancer_idle(game_t *game, enemy_t *enemy);
int necromancer_dead(game_t *game, enemy_t *enemy);
int move_enemy(enemy_t *enemy, float lenght);
void face_player(game_t *game, enemy_t *enemy);
int destroy_enemies(game_t *game);
int destroy_enemy_contents(enemy_t *enemy);
int destroy_enemy_and_update_xp(game_t *game, enemy_t *enemy);
int init_enemy_element_and_hp(game_t *game, enemy_t *dest);
enemy_t *create_lich_boss(game_t *game);
int lich_boss_dead(game_t *game, enemy_t *enemy);
int lich_boss_attacking(game_t *game, enemy_t *enemy);
int lich_boss_idle(game_t *game, enemy_t *enemy);
int lich_boss_update(game_t *game, enemy_t *enemy);
int lich_boss_summoning(game_t *game, enemy_t *enemy);
void lich_boss_casting(game_t *game, enemy_t *enemy);
int change_enemy_element(game_t *game, enemy_t *enemy);
int water_lich_spell(game_t *game, enemy_t *enemy);
int fire_lich_spell(game_t *game, enemy_t *enemy);
int rock_lich_spell(game_t *game, enemy_t *enemy);
int ice_lich_spell(game_t *game, enemy_t *enemy);
enemy_t *create_pnj_quest(game_t *game, sfVector2f pos);
int pnj_quest_update(game_t *game, enemy_t *enemy);
void lich_boss_summon(game_t *game);

#endif
