/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** particle
*/

#include "SFML/Graphics.h"
#include "rpg.h"

#ifndef PARTICLE_H
    #define PARTICLE_H

typedef enum particle_type_e {
    FIRE_PART,
    SNOW_PART,
    RAIN_PART,
    ROCK_PART,
    STAR_PART,
    XP_PART,
    SKULL_PART,
    NB_PARTICLES
} particle_type_t;

typedef struct particle_s {
    sfVector2f pos;
    sfColor color;
    int lifetime;
    sfVector2f spd;
    particle_type_t type;
    int (*update)(game_t *, struct particle_s *);
    float rot;
    sfVector2f scale;
} particle_t;

    #define MORNINGCOLOR ((sfColor){.r = 255, .g = 255, .b = 255, .a = 50})
    #define AFTERNOONCOLOR ((sfColor){.r = 200, .g = 153, .b = 51, .a = 50})
    #define EVENINGCOLOR ((sfColor){.r = 50, .g = 152, .b = 150, .a = 50})
    #define NIGHTCOLOR ((sfColor){.r = 0, .g = 0, .b = 0, .a = 150})

    #define RAIN_COLOR ((sfColor){.r = 0, .g = 204, .b = 255, .a = 255})
    #define SKULL_COLOR ((sfColor){.r = 255, .g = 255, .b = 255, .a = 50})
    #define CLICK_COLOR ((sfColor){.r = 72, .g = 72, .b = 72, .a = 255})
    #define NO_COLOR ((sfColor){.r = 255, .g = 255, .b = 255, .a = 255})
    #define RAND_COLOR ((sfColor){.r = rand() % 256, \
                                .g = rand() % 256, \
                                .b = rand() % 256, \
                                .a = 255})

particle_t *create_rain_particle(void);
int update_particles(game_t *game);
int draw_particles(game_t *game);
int clear_particles(game_t *game);
int update_rainparticle(game_t *game, particle_t *particle);
int update_snowparticle(game_t *game __attribute__((unused)), particle_t
*particle);
particle_t *create_snow_particle(void);
int update_weather(game_t *game);
particle_t *create_star_particle(game_t *game);
int update_starparticle(game_t *game, particle_t *particle);
int destroy_particles(game_t *game);
int update_xpparticle(game_t *game, particle_t *particle);
particle_t *create_xp_particle(game_t *game);
particle_t *create_star_particle_on_player(game_t *game);
int update_skullparticle(game_t *game, particle_t *particle);
particle_t *create_star_particle_on_duck(game_t *game, sfVector2f pos,
        sfColor color);
int update_star_particle_on_duck(game_t *game, particle_t *particle);
particle_t *create_end_screen_star_particle(game_t *game, sfVector2f pos,
        sfColor color);

#endif
