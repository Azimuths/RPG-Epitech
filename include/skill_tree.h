/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** skill_points
*/

#ifndef SKILL_POINTS_H
    #define SKILL_POINTS_H

typedef struct skill_tree_s {
    int velocity_level;
    int health_level;
    int attack_level;
} skill_tree_t;

void on_click_skill_speed_first(game_t *game);
void on_click_skill_speed_second(game_t *game);
void on_click_skill_speed_third(game_t *game);
void on_click_skill_health_first(game_t *game);
void on_click_skill_health_second(game_t *game);
void on_click_skill_health_third(game_t *game);
void on_click_skill_atk_first(game_t *game);
void on_click_skill_atk_second(game_t *game);
void on_click_skill_atk_third(game_t *game);

#endif
