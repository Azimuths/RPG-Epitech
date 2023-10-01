/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** sounds
*/

#include <SFML/Audio.h>

#ifndef SOUNDS_H_
    #define SOUNDS_H_

typedef struct game_s game_t;

typedef struct sounds_s {
    sfSound *sound;
    sfSoundBuffer *buffer;
} sounds_t;

typedef struct every_sounds_s {
    sounds_t *click;
    sfMusic *music;
    sounds_t *attack;
} every_sounds_t;

sounds_t *create_sound(const char *filepath, float volume);
sfMusic *create_music(const char *filepath, float volume);
void change_music(game_t *game, char *filename);
void delete_sounds(every_sounds_t *sounds);
int init_sounds(game_t *rpg);
void destroy_music(sfMusic *music);
void set_volume_off(game_t *game);
void set_volume_on(game_t *game);

#endif
