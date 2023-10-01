/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "rpg.h"
#include "my.h"

int main(const int argc __attribute__((unused)), char **argv, char **env)
{
    if (check_env(env))
        return 84;
    if (my_strcmp(argv[1], "-h"))
        return print_help();
    else
        return my_rpg();
}
