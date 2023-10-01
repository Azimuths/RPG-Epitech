/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_config
*/

#include "config.h"
#include "rpg.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *get_command(FILE *file)
{
    char *ptr = read_line_from_stream(file);
    int i = 0;

    if (ptr == NULL)
        return NULL;
    if (*ptr != '[') {
        free(ptr);
        return my_null_error("Command not found : Syntax error on [");
    }
    for (i = 1; ptr[i] != ']' && ptr[i] != '\0'; i++);
    if (ptr[i] != ']') {
        free(ptr);
        return my_null_error("Command not found : Syntax error on ]");
    }
    ptr[++i] = '\0';
    return ptr;
}

char **get_value(int indent, FILE *file)
{
    char *ptr = read_line_from_stream(file);
    int i = 0;
    char **dest = NULL;

    if (ptr == NULL)
        return my_null_error("Failed to read line\n");
    for (i = 0; i < indent * 4; ++i)
        if (ptr[i] != ' ')
            return my_null_error("wrong indent\n");
    if (ptr[i] == ' ')
        return my_null_error("wrong indent\n");
    dest = my_str_to_word_array(&(ptr[i]), ",");
    free(ptr);
    return dest;
}

int update_config(char *cmd, char **args, config_t *dest)
{
    char *commands[] = {"[SKIN]", "[SNOW_TEXTURE]", "[RAIN_TEXTURE]",
            "[CLICK_TEXTURE]", "[VIDEOMODE]", NULL};
    int (*update_func[])(char **, config_t *) = {
            conf_update_skin, conf_update_snowtext, conf_update_raintext,
            conf_update_clicktext, conf_update_window_size, NULL};

    for (int i = 0; commands[i] != NULL; ++i) {
        if (my_strcmp(commands[i], cmd) == 1)
            return update_func[i](args, dest);
    }
    return my_put_error("Command not found\n");
}

int parse_config_file(config_t *config, FILE *file)
{
    char *cmd = NULL;
    char **args = NULL;

    cmd = get_command(file);
    while (cmd != NULL) {
        args = get_value(1, file);
        if (args == NULL)
            return my_put_error("Failed to parse args\n");
        if (update_config(cmd, args, config) != 0)
            return 84;
        destroy_array((void **)args);
        free(cmd);
        cmd = get_command(file);
    }
    free(cmd);
    return 0;
}

config_t *load_config(void)
{
    config_t *dest = init_config();

    FILE *file = fopen(".config", "a+");
    if (file == NULL)
        return my_null_error("Failed to open config file\n");
    if (parse_config_file(dest, file) == 84)
        return NULL;
    return dest;
}
