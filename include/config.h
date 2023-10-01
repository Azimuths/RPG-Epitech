/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** config
*/

#include "player.h"

#ifndef CONFIG_H
    #define CONFIG_H

typedef struct config_s {
    player_textures_t skin;
    char *rain_text_file;
    char *click_text_file;
    char *snow_text_file;
    char *rock_text_file;
    char *fire_text_file;
    char *vanilla_duck_text_file;
    char *fire_duck_text_file;
    char *water_duck_text_file;
    char *ice_duck_text_file;
    char *rock_duck_text_file;
    char *necro_text_file;
    char *dread_knight_text_file;
    char *death_knight_text_file;
    char *xp_text_file;
    char *lich_text_file;
    char *skull_text_file;
    sfVideoMode videomode;
} config_t;

    #define STAR_TEXT "assets/part/star.png"
    #define RAIN_TEXT "assets/part/rain_2.png"
    #define SNOW_TEXT "assets/part/flocon.png"
    #define ROCK_TEXT "assets/part/rock.png"
    #define FIRE_TEXT "assets/part/fire.png"
    #define VANILLA_DUCK_TEXT "assets/duck/donald.png"
    #define FIRE_DUCK_TEXT "assets/duck/tyler.png"
    #define WATER_DUCK_TEXT "assets/duck/valerie.png"
    #define ICE_DUCK_TEXT "assets/duck/patrick.png"
    #define ROCK_DUCK_TEXT "assets/duck/denis.png"
    #define XP_TEXT "assets/part/exp.png"
    #define SKULL_TEXT "assets/part/fire.png"

config_t *load_config(void);
int conf_update_skin(char **args, config_t *dest);
config_t *init_config(void);
int conf_update_snowtext(char **args, config_t *dest);
int conf_update_raintext(char **args, config_t *dest);
int conf_update_clicktext(char **args, config_t *dest);
int conf_update_window_size(char **args, config_t *dest);

#endif
