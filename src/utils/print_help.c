/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** print_help
*/

#include <fcntl.h>
#include <unistd.h>

#include "macro.h"
#include "my.h"
#include "rpg.h"

int print_help(void)
{
    int fd = open(HELP, O_RDONLY);
    char buffer[412];

    if (read(fd, buffer, 411) != -1) {
        write(1, buffer, 411);
        write(1, "\n", 1);
    }
    else
        return my_put_error("./my_rpg: Failed to load help file\n");
    close(fd);
    return 0;
}
