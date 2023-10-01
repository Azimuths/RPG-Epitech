/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player
*/

#include "SFML/Graphics.h"
#include "rpg.h"

#ifndef PLAYER_H
    #define PLAYER_H

typedef enum player_status_e {
    PLAYER_IDLE,
    PLAYER_MOVING,
    PLAYER_ATTACKING,
    PLAYER_DEAD
} player_status_t;

typedef enum dir_e {
    DOWN,
    LEFT,
    RIGHT,
    UP
} dir_t;

typedef struct player_s {
    sfSprite *sprite;
    sfSprite *sword;
    sfTexture **textures;
    sfTexture *sword_text;
    sfIntRect rect;
    sfIntRect sword_rect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f velocity;
    dir_t dir;
    player_status_t status;
    sfClock *clock;
    int hp;
    int max_hp;
    int dmg;
    int spd;
    int level;
    int exp;
    sfFloatRect hitbox_size;
} player_t;

typedef enum player_textures_e {
    HERO1,
    HERO2,
    VILLAGER3,
    VILLAGER7,
    VILLAGER8,
    VILLAGER9,
    NB_PLAYER_TEXTURES
} player_textures_t;

    #define HERO1_SPRITE "assets/hero/hero1.png"
    #define HERO2_SPRITE "assets/hero/hero2.png"
    #define VILLAGER3_SPRITE "assets/hero/villager3.png"
    #define VILLAGER7_SPRITE "assets/hero/villager7.png"
    #define VILLAGER8_SPRITE "assets/hero/villager8.png"
    #define VILLAGER9_SPRITE "assets/hero/villager9.png"
    #define SWORD_SPRITE "assets/hero/sword.png"

player_t *init_player(player_textures_t skin);
int destroy_player(player_t *player);
int draw_player(game_t *game);
int move_player(game_t *game);
int change_dir(game_t *game);
int add_force(float *velocity, float value);
int animate_player(player_t *player);
int animate_player_attacking(player_t *player);
int animate_player_idle(player_t *player);
int animate_player_moving(player_t *player);
int update_player_state(player_t *player);
int destroy_player(player_t *player);
float get_player_distance(game_t *game, sfVector2f pos);
sfVector2f get_player_vector(game_t *game, sfVector2f pos);
int move_player_home(game_t *game);
int sword_shoot(game_t *game, player_t *player);
int attack_player(game_t *game);

#endif
