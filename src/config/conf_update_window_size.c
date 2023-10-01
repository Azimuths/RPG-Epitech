/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** conf_update_window_size
*/

#include "config.h"
#include "my.h"
#include "SFML/Graphics.h"

int conf_update_window_size(char **args, config_t *dest)
{
    size_t count = 0;
    const sfVideoMode *modes = sfVideoMode_getFullscreenModes(&count);

    if (my_arrlen((void **)args) != 3)
        return my_put_error("VIDEOMODE : invalid args");
    dest->videomode.width = my_getnbr(args[0]);
    dest->videomode.height = my_getnbr(args[1]);
    dest->videomode.bitsPerPixel = my_getnbr(args[2]);
    if (dest->videomode.height < 0 || dest->videomode.width < 0 ||
        dest->videomode.bitsPerPixel < 0)
        return my_put_error("VIDEOMODE : Invalid values");
    if (!sfVideoMode_isValid(dest->videomode)) {
        my_putstr("Avaliable modes:\n");
        for (int i = 0; i < count; ++i) {
            my_printf("%u, %u , %u\n", modes[i].width,  modes[i].height,
                    modes[i].bitsPerPixel);
        }
        return my_put_error("VIDEOMODE : Invalid video mode");
    }
    return 0;
}
