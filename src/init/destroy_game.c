/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_game
*/

#include "particle.h"
#include "skill_tree.h"
#include "projectile.h"
#include "enemy.h"
#include "player.h"
#include "my.h"
#include "my_linked_list.h"
#include "sounds.h"
#include "config.h"
#include "inventory.h"
#include "editor.h"
#include <SFML/Graphics/View.h>
#include "quest.h"
#include <stdlib.h>

void destroy_game_second(game_t *game)
{
    destroy_main_menu(game->all_obj);
    destroy_pause_menu(game->pause);
    destroy_settings_menu(game->settings);
    destroy_pause_settings_menu(game->pause_settings);
    destroy_htp_menu(game->htp);
    destroy_skill_menu(game->skill);
    destroy_text_skill_menu(game->skill_text);
    destroy_text_settings_menu(game->text);
    destroy_stats_menu(game->stats);
    destroy_text_stats_menu(game->stats_text);
    destroy_quest_menu(game->quest);
    destroy_end_menu(game->end_screen);
    free_game(game->editor);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock_game);
    sfClock_destroy(game->clock_anim);
    destroy_projectiles(game, &(game->projectiles));
    destroy_projectiles(game, &(game->enemy_proj));
    destroy_particles(game);
    destroy_enemies(game);
    destroy_all_texture(game->textures);
    destroy_player(game->player);
    destroy_enemies(game);
    delete_sounds(game->sounds);
    destroy_inventory(game->inventory);
    map_destroy(game);
    destroy_game_second(game);
    free(game->config);
    free(game);
}

int reset_game(game_t *game)
{
    destroy_projectiles(game, &(game->projectiles));
    destroy_projectiles(game, &(game->enemy_proj));
    destroy_particles(game);
    destroy_enemies(game);
    sfView_destroy(game->map->view);
    game->map->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    game->map->screen_pos = ((sfVector2u){1, 1});
    sfView_move(game->map->view, ((sfVector2f){1920, 1056}));
    game->player->hp = 100;
    game->map->offset = (sfVector2f){10, 5};
    game->map->pos = (sfVector2f){0, 0};
    game->time = 0;
    game->weather = CLEAR;
    game->projectiles = NULL;
    game->enemies = NULL;
    game->enemy_proj = NULL;
    game->particles = NULL;
    game->player->velocity = ((sfVector2f){0.0, 0.0});
    return 0;
}
