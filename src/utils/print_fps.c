/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** print_fps
*/

#include "rpg.h"
#include <stdlib.h>

static int length(int nb)
{
    int length = 1;

    if (nb < 0)
        return (0);
    while (nb > 9) {
        length += 1;
        nb = nb / 10;
    }
    return (length);
}

char *int_to_str(int value)
{
    int len = length(value);
    char *str = malloc(sizeof(char) * (len + 1));
    int index = len - 1;
    int result = 0;

    while (index >= 0) {
        result = value % 10;
        value /= 10;
        str[index] = result + '0';
        index -= 1;
    }
    str[len] = '\0';
    return (str);
}

void calculate_framerate(game_t *game)
{
    static int start = 1;
    static sfClock *clock;
    static int fps = 0;
    char *fps_string = NULL;

    if (start == 1) {
        clock = sfClock_create();
        start = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        fps_string = int_to_str(fps);
        sfText_setString(game->text->fps_text->text, fps_string);
        free(fps_string);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}
