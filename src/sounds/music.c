/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** music
*/

#include "sounds.h"

sfMusic *create_music(const char *filepath, float volume)
{
    sfMusic *music = NULL;

    if (!(music = sfMusic_createFromFile(filepath)))
        return NULL;
    sfMusic_setVolume(music, volume);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}

void destroy_music(sfMusic *music)
{
    sfMusic_destroy(music);
}
