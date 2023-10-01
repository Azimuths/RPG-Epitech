/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_config
*/

#include "config.h"
#include "my.h"
#include "particle.h"
#include "projectile.h"
#include "enemy.h"
#include "macro.h"

void init_config_second(config_t *config)
{
    config->necro_text_file = NECRO_TEXT;
    config->fire_text_file = FIRE_TEXT;
    config->rock_text_file = ROCK_TEXT;
    config->xp_text_file = XP_TEXT;
    config->skull_text_file = SKULL_TEXT;
    config->videomode = ((sfVideoMode){WIDTH, HEIGHT, BPP});
}

config_t *init_config(void)
{
    config_t *config = my_memset(sizeof(config_t), NULL);

    config->skin = HERO1;
    config->snow_text_file = SNOW_TEXT;
    config->rain_text_file = RAIN_TEXT;
    config->click_text_file = STAR_TEXT;
    config->vanilla_duck_text_file = VANILLA_DUCK_TEXT;
    config->water_duck_text_file = WATER_DUCK_TEXT;
    config->fire_duck_text_file = FIRE_DUCK_TEXT;
    config->ice_duck_text_file = ICE_DUCK_TEXT;
    config->rock_duck_text_file = ROCK_DUCK_TEXT;
    config->death_knight_text_file = DEATH_KNIGHT_TEXT;
    config->dread_knight_text_file = DREAD_KNIGHT_TEXT;
    config->lich_text_file = LICH_TEXT;
    init_config_second(config);
    return config;
}
