/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** sounds
*/

#include "sounds.h"
#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

sounds_t *create_sound(const char *filepath, float volume)
{
    sounds_t *sound = malloc(sizeof(sounds_t));
    sfSoundBuffer *buffer = NULL;
    sfSound *sounds = NULL;

    if (!(buffer = sfSoundBuffer_createFromFile(filepath)))
        return NULL;
    if (!(sounds = sfSound_create()))
        return NULL;
    sfSound_setBuffer(sounds, buffer);
    sfSound_setVolume(sounds, volume);
    sound->buffer = buffer;
    sound->sound = sounds;
    return sound;
}

int init_sounds(game_t *rpg)
{
    every_sounds_t *sounds = malloc(sizeof(every_sounds_t));

    sounds->click = create_sound(CLICK_SOUND, 50.0);
    sounds->attack = create_sound(ATTACK_SOUND, 30.0);
    sounds->music = create_music(MAIN_MUSIC, 50.0);
    if (sounds->click == NULL || sounds->attack == NULL ||
    sounds->music == NULL)
        return 84;
    rpg->sounds = sounds;
    return 0;
}

void delete_sounds(every_sounds_t *sounds)
{
    sfSound_destroy(sounds->click->sound);
    sfSound_destroy(sounds->attack->sound);
    sfSoundBuffer_destroy(sounds->click->buffer);
    sfSoundBuffer_destroy(sounds->attack->buffer);
    free(sounds->click);
    destroy_music(sounds->music);
    free(sounds);
}
