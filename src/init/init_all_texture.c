/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_all_texture
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"
#include "config.h"
#include "particle.h"
#include "projectile.h"
#include "stdlib.h"
#include "enemy.h"

sfTexture **init_all_projectile_texture(game_t *game)
{
    sfTexture **dest = my_memset(sizeof(sfTexture *) * NB_PROJECTILES, NULL);

    dest[VANILLA_DUCK] = sfTexture_createFromFile(
            game->config->vanilla_duck_text_file, NULL);
    dest[FIRE_DUCK] = sfTexture_createFromFile(
            game->config->fire_duck_text_file, NULL);
    dest[WATER_DUCK] = sfTexture_createFromFile(
            game->config->water_duck_text_file, NULL);
    dest[ROCK_DUCK] = sfTexture_createFromFile(
            game->config->rock_duck_text_file, NULL);
    dest[ICE_DUCK] = sfTexture_createFromFile(
            game->config->ice_duck_text_file, NULL);
    for (int i = 0; i < NB_PROJECTILES; ++i)
        if (dest[i] == NULL)
            return my_null_error("Failed to load projectile");
    return dest;
}

sfTexture **init_all_particle_texture(game_t *game)
{
    sfTexture **dest = my_memset(sizeof(sfTexture *) * NB_PARTICLES, NULL);

    dest[STAR_PART] = sfTexture_createFromFile(
            game->config->click_text_file, NULL);
    dest[RAIN_PART] = sfTexture_createFromFile(
            game->config->rain_text_file, NULL);
    dest[SNOW_PART] = sfTexture_createFromFile(
            game->config->snow_text_file, NULL);
    dest[FIRE_PART] = sfTexture_createFromFile(
            game->config->fire_text_file, NULL);
    dest[ROCK_PART] = sfTexture_createFromFile(
            game->config->rock_text_file, NULL);
    dest[XP_PART] = sfTexture_createFromFile(
            game->config->xp_text_file, NULL);
    dest[SKULL_PART] = sfTexture_createFromFile(
            game->config->skull_text_file, NULL);
    for (int i = 0; i < NB_PARTICLES; ++i)
        if (dest[i] == NULL)
            return my_null_error("Failed to load particle");
    return dest;
}

sfTexture **init_all_enemies_texture(game_t *game)
{
    sfTexture **dest = my_memset(sizeof(sfTexture *) * NB_ENEMY_TYPES, NULL);

    dest[DREAD_KNIGHT] = sfTexture_createFromFile(
            game->config->dread_knight_text_file, NULL);
    dest[DEATH_KNIGHT] = sfTexture_createFromFile(
            game->config->death_knight_text_file, NULL);
    dest[NECROMANCER] = sfTexture_createFromFile(
            game->config->necro_text_file, NULL);
    dest[LICH] = sfTexture_createFromFile(
            game->config->lich_text_file, NULL);
    for (int i = 0; i < NB_ENEMY_TYPES; ++i)
        if (dest[i] == NULL)
            return my_null_error("Failed to load enemy\n");
    return dest;
}

all_texture_t *init_all_texture(game_t *game)
{
    all_texture_t *dest = my_memset(sizeof(all_texture_t), NULL);

    dest->particles = init_all_particle_texture(game);
    dest->projectile = init_all_projectile_texture(game);
    dest->enemies = init_all_enemies_texture(game);
    if (dest->particles == NULL || dest->projectile == NULL || dest->enemies
    == NULL)
        return NULL;
    return dest;
}

void destroy_all_texture(all_texture_t *all_text)
{
    for (int i = 0; i < NB_PARTICLES; ++i) {
        sfTexture_destroy(all_text->particles[i]);
    }
    free(all_text->particles);
    for (int i = 0; i < NB_PROJECTILES; ++i) {
        sfTexture_destroy(all_text->projectile[i]);
    }
    free(all_text->projectile);
    for (int i = 0; i < NB_ENEMY_TYPES; ++i) {
        sfTexture_destroy(all_text->enemies[i]);
    }
    free(all_text->enemies);
    free(all_text);
}
